import sys
import math

def compute_p_from_c(c, eps=1e-12):
    """
    给定暴击系数 c，计算长期期望暴击率 p。
    """
    if c <= 0:
        return 0.0
    # 计算期望攻击次数 E = sum_{k=0..∞} (k+1) * P(暴击发生在第k+1次)
    prob_no_crit = 1.0  # 连续未暴击的概率累积
    E = 0.0
    k = 0
    while prob_no_crit > eps and k < 10**7:  # 安全限制
        prob_crit_now = min(1.0, c * (k + 1))
        prob_hit_at_this_attack = prob_no_crit * prob_crit_now
        E += (k + 1) * prob_hit_at_this_attack
        prob_no_crit *= (1.0 - prob_crit_now)
        k += 1
    # 如果 prob_no_crit 还很大（理论上不会，但预防）
    # 如果最后 prob_no_crit 还有残留，则剩下的情况是永远不暴击？不可能，概率最终为1
    # 所以 E 已算好
    if E == 0:
        return 0.0
    return 1.0 / E

def find_c_for_p(target_p):
    """
    二分查找 c，使得 compute_p_from_c(c) ≈ target_p
    """
    lo, hi = 1e-12, 1.0
    # 处理 p=1 的特殊情况
    if abs(target_p - 1.0) < 1e-12:
        return 1.0
    # 二分迭代
    for _ in range(100):  # 足够多次
        mid = (lo + hi) / 2
        p_mid = compute_p_from_c(mid)
        if p_mid < target_p:
            lo = mid
        else:
            hi = mid
        if hi - lo < 1e-15:
            break
    return (lo + hi) / 2

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    out_lines = []
    for i in range(t):
        p = float(data[i + 1])
        c = find_c_for_p(p)
        out_lines.append(f"{c:.15f}")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()