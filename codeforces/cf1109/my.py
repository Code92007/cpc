#!/usr/bin/env python3
"""根据 asset_id 从 asset-center 获取视频播放地址并下载到本地。"""
from __future__ import annotations
import argparse
import json
import os
import re
import sys
from pathlib import Path
from typing import Any
from urllib import error, parse, request
DEFAULT_ASSET_CENTER_BASE_URL = "http://asset-center"
DEFAULT_OUTPUT_DIR = Path("downloads/videos")
CHUNK_SIZE = 1024 * 1024
OSS_PUBLIC_ENDPOINT_RE = re.compile(r"(\.oss-us-southeast-1)\.aliyuncs\.com")
def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="根据视频 asset_id 下载视频文件。"
    )
    parser.add_argument("asset_id", help="视频资产 ID")
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        help="输出文件路径；不指定时写入 downloads/videos/{asset_id}.mp4",
    )
    parser.add_argument(
        "--output-dir",
        type=Path,
        default=DEFAULT_OUTPUT_DIR,
        help="未指定 --output 时的输出目录，默认 downloads/videos",
    )
    parser.add_argument(
        "--asset-center-base-url",
        default=os.getenv("ASSET_CENTER_BASE_URL", DEFAULT_ASSET_CENTER_BASE_URL),
        help="asset-center base URL，默认读取 ASSET_CENTER_BASE_URL 或 http://asset-center",
    )
    parser.add_argument(
        "--get-asset-api",
        help="资产详情接口，默认 {asset-center-base-url}/api/v1/assets",
    )
    parser.add_argument(
        "--get-play-info-api",
        help="视频播放地址接口，默认 {asset-center-base-url}/api/v1/content/video/urls",
    )
    parser.add_argument(
        "--storage",
        help="覆盖资产元数据中的 video.storage，例如 volc/aliyun",
    )
    parser.add_argument(
        "--internal",
        action=argparse.BooleanOptionalAction,
        default=True,
        help="获取内网播放地址，默认 true；外网下载可用 --no-internal",
    )
    parser.add_argument(
        "--type",
        default="mp4",
        dest="file_type",
        help="播放地址类型，默认 mp4",
    )
    parser.add_argument(
        "--timeout",
        type=float,
        default=60,
        help="接口请求和单次下载读取超时秒数，默认 60",
    )
    parser.add_argument(
        "--overwrite",
        action="store_true",
        help="目标文件已存在时覆盖",
    )
    parser.add_argument(
        "--print-url",
        action="store_true",
        help="打印解析出的播放地址",
    )
    parser.add_argument(
        "--use-internal-oss-url",
        action=argparse.BooleanOptionalAction,
        default=True,
        help="下载 OSS 地址时将公开 endpoint 改为 internal endpoint，默认 true",
    )
    return parser.parse_args()
def http_json(
    method: str,
    url: str,
    *,
    payload: dict[str, Any] | None = None,
    timeout: float,
) -> dict[str, Any]:
    data = None if payload is None else json.dumps(payload).encode("utf-8")
    http_request = request.Request(
        url,
        data=data,
        method=method,
        headers={"Content-Type": "application/json"},
    )
    try:
        with request.urlopen(http_request, timeout=timeout) as response:
            raw = response.read().decode("utf-8")
    except error.HTTPError as exc:
        detail = exc.read().decode("utf-8", errors="replace")
        raise RuntimeError(f"{method} {url} failed: HTTP {exc.code}: {detail}") from exc
    except error.URLError as exc:
        raise RuntimeError(f"{method} {url} failed: {exc.reason}") from exc
    try:
        result = json.loads(raw)
    except json.JSONDecodeError as exc:
        raise RuntimeError(f"{method} {url} returned non-JSON response: {raw[:500]}") from exc
    if not isinstance(result, dict):
        raise RuntimeError(f"{method} {url} returned unexpected JSON: {result!r}")
    return result
def response_data(response: dict[str, Any]) -> dict[str, Any]:
    data = response.get("data", response)
    if not isinstance(data, dict):
        raise RuntimeError(f"响应 data 不是对象: {response!r}")
    return data
def fetch_asset(asset_id: str, *, get_asset_api: str, timeout: float) -> dict[str, Any]:
    url = f"{get_asset_api.rstrip('/')}/{parse.quote(asset_id, safe='')}"
    return response_data(http_json("GET", url, timeout=timeout))
def extract_video_item(asset: dict[str, Any]) -> tuple[str, str]:
    if str(asset.get("asset_type", "")).lower() not in {"", "video"}:
        raise RuntimeError(f"asset_type={asset.get('asset_type')!r} 不是 video")
    items = asset.get("items")
    if not isinstance(items, list) or not items:
        raise RuntimeError(f"资产响应中没有 items: {asset!r}")
    for item in items:
        if not isinstance(item, dict):
            continue
        video = item.get("video")
        if not isinstance(video, dict):
            continue
        video_id = str(video.get("video_id") or video.get("id") or "").strip()
        storage = str(video.get("storage") or "volc").strip()
        if video_id:
            return video_id, storage
    raise RuntimeError(f"资产 items 中没有 video.video_id: {asset!r}")
def fetch_play_url(
    video_id: str,
    *,
    storage: str,
    internal: bool,
    file_type: str,
    get_play_info_api: str,
    timeout: float,
) -> str:
    payload = {
        "ids": [video_id],
        "internal": internal,
        "storage": storage,
        "type": file_type,
    }
    data = response_data(http_json("POST", get_play_info_api, payload=payload, timeout=timeout))
    items = data.get("items")
    if not isinstance(items, list) or not items:
        raise RuntimeError(f"播放地址响应中没有 data.items: {data!r}")
    first = items[0]
    if not isinstance(first, dict):
        raise RuntimeError(f"播放地址 item 不是对象: {first!r}")
    video_url = str(first.get("url") or "").strip()
    if not video_url:
        raise RuntimeError(f"播放地址 item 中没有 url: {first!r}")
    return video_url
def to_internal_oss_url(url: str) -> str:
    if "-internal.aliyuncs.com" in url:
        return url
    return OSS_PUBLIC_ENDPOINT_RE.sub(r"\1-internal.aliyuncs.com", url)
def infer_suffix(video_url: str, default: str) -> str:
    path = parse.urlparse(video_url).path
    suffix = Path(path).suffix
    if suffix and len(suffix) <= 10:
        return suffix
    return f".{default.lstrip('.')}"
def output_path_for(args: argparse.Namespace, video_url: str) -> Path:
    if args.output:
        return args.output
    return args.output_dir / f"{args.asset_id}{infer_suffix(video_url, args.file_type)}"
def download_to_file(
    video_url: str,
    output_path: Path,
    *,
    timeout: float,
    overwrite: bool,
) -> int:
    if output_path.exists() and not overwrite:
        raise RuntimeError(f"目标文件已存在，使用 --overwrite 覆盖: {output_path}")
    output_path.parent.mkdir(parents=True, exist_ok=True)
    temp_path = output_path.with_name(f"{output_path.name}.part")
    try:
        with request.urlopen(video_url, timeout=timeout) as response:
            total = response.headers.get("Content-Length")
            total_bytes = int(total) if total and total.isdigit() else None
            downloaded = 0
            with temp_path.open("wb") as file:
                while True:
                    chunk = response.read(CHUNK_SIZE)
                    if not chunk:
                        break
                    file.write(chunk)
                    downloaded += len(chunk)
                    if total_bytes:
                        percent = downloaded / total_bytes * 100
                        print(
                            f"\r下载中 {downloaded / 1024 / 1024:.1f}/"
                            f"{total_bytes / 1024 / 1024:.1f} MiB ({percent:.1f}%)",
                            end="",
                            file=sys.stderr,
                        )
                    else:
                        print(
                            f"\r下载中 {downloaded / 1024 / 1024:.1f} MiB",
                            end="",
                            file=sys.stderr,
                        )
            print(file=sys.stderr)
    except error.HTTPError as exc:
        detail = exc.read().decode("utf-8", errors="replace")
        raise RuntimeError(f"下载失败: HTTP {exc.code}: {detail}") from exc
    except error.URLError as exc:
        raise RuntimeError(f"下载失败: {exc.reason}") from exc
    except Exception:
        if temp_path.exists():
            temp_path.unlink()
        raise
    temp_path.replace(output_path)
    return output_path.stat().st_size
def main() -> int:
    args = parse_args()
    base_url = args.asset_center_base_url.rstrip("/")
    get_asset_api = args.get_asset_api or f"{base_url}/api/v1/assets"
    get_play_info_api = args.get_play_info_api or f"{base_url}/api/v1/content/video/urls"
    try:
        asset = fetch_asset(args.asset_id, get_asset_api=get_asset_api, timeout=args.timeout)
        video_id, asset_storage = extract_video_item(asset)
        storage = args.storage or asset_storage
        video_url = fetch_play_url(
            video_id,
            storage=storage,
            internal=args.internal,
            file_type=args.file_type,
            get_play_info_api=get_play_info_api,
            timeout=args.timeout,
        )
        download_url = to_internal_oss_url(video_url) if args.use_internal_oss_url else video_url
        output_path = output_path_for(args, download_url)
        if args.print_url:
            print(video_url)
        print(
            f"asset_id={args.asset_id} video_id={video_id} storage={storage} "
            f"internal={args.internal}",
            file=sys.stderr,
        )
        size = download_to_file(
            download_url,
            output_path,
            timeout=args.timeout,
            overwrite=args.overwrite,
        )
    except RuntimeError as exc:
        print(f"[ERROR] {exc}", file=sys.stderr)
        return 1
    print(f"已下载: {output_path} ({size / 1024 / 1024:.2f} MiB)")
    return 0
if __name__ == "__main__":
    raise SystemExit(main())