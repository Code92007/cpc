#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef __int128 i128;
typedef pair<i128, i128> P; // 分数 {分子, 分母}
#define fi first
#define se second
#define pb push_back
const int N = 2e5 + 10;

int n, a[N], b[N];

// __int128 输出
void print_i128(i128 x) {
    if (x == 0) { printf("0"); return; }
    if (x < 0) { printf("-"); x = -x; }
    string s;
    while (x > 0) { s += char('0' + x % 10); x /= 10; }
    reverse(s.begin(), s.end());
    cout << s;
}

i128 abs128(i128 x) { return x < 0 ? -x : x; }
i128 gcd128(i128 x, i128 y) { return y == 0 ? x : gcd128(y, x % y); }

// 比较两个分数 x < y
bool cmp_frac(const P& x, const P& y) {
    return x.fi * y.se < y.fi * x.se;
}

// 核心计算：在当前 a, b 状态下，假设最优斜率在 [0,1] 范围内，计算最小总距离
P calc() {
    // 收集所有 0 <= B_i/A_i <= 1 的点
    vector<pair<ll, int>> v;
    rep(i, 1, n) {
        if (a[i] != 0) { // 跳过 A_i = 0
            ll p = b[i], q = a[i];
            if (q < 0) { p = -p; q = -q; } // 保证分母为正
            if (p >= 0 && p <= q) { // 只保留斜率在 [0,1] 的点
                v.pb({p, i});
            }
        }
    }
    if (v.empty()) return {(i128)1e36, 1};

    // 按分数 B_i / A_i 排序
    sort(v.begin(), v.end(), [&](const pair<ll, int>& x, const pair<ll, int>& y) {
        return (i128)x.fi * a[y.se] < (i128)y.fi * a[x.se];
    });

    // 找加权中位数，权重是 |A_i|
    ll tot = 0; for (auto& p : v) tot += abs(a[p.se]);
    ll cur = 0; int med = -1;
    for (auto& p : v) {
        cur += abs(a[p.se]);
        if (cur * 2 >= tot) { med = p.se; break; }
    }

    if (med != -1) {
        // 最优斜率 k = B_med / A_med
        // 计算总距离: sum |B_i - k*A_i| = sum |B_i*A_med - B_med*A_i| / |A_med|
        i128 num = 0, den = abs(a[med]);
        rep(i, 1, n) {
            num += abs128((i128)b[i] * a[med] - (i128)b[med] * a[i]);
        }
        i128 g = gcd128(num, den);
        return {num / g, den / g};
    }
    return {(i128)1e36, 1};
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, n) scanf("%d", &b[i]);

    P ans = {(i128)1e36, 1};
    P t;

    // 四次连续变换，覆盖所有斜率情况，不需要还原！
    t = calc(); if (cmp_frac(t, ans)) ans = t;          // 1. (A, B)
    rep(i, 1, n) b[i] = -b[i];
    t = calc(); if (cmp_frac(t, ans)) ans = t;          // 2. (A, -B)
    rep(i, 1, n) swap(a[i], b[i]);
    t = calc(); if (cmp_frac(t, ans)) ans = t;          // 3. (-B, A)
    rep(i, 1, n) b[i] = -b[i];
    t = calc(); if (cmp_frac(t, ans)) ans = t;          // 4. (-B, -A)

    print_i128(ans.fi);
    printf(" ");
    print_i128(ans.se);
    printf("\n");

    return 0;
}