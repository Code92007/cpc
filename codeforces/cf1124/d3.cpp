#include <iostream>
using namespace std;
const int N = 2e5 + 5, W = 16, X[] = {0, 3, 5, 6, 9, 10, 12, 15};
int t, n, q, a[N], cnt[W];
void solve() {
    int ans = 0, sum = 0;
    for (int i = 0; i < 16; ++i)
        if (i % 3 == 0)
            ans += cnt[i];
        else if (i % 5 == 0)
            ans += cnt[i] - cnt[i] % 2;
        else
            sum += cnt[i];
    if ((cnt[5] & 1) && (cnt[10] & 1))
        ans += 2;
    else if (((cnt[5] & 1) || (cnt[10] & 1)) && sum + ans)
        ++ans;
    cout << ans << " ";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    for (cin >> t; t; --t) {
        cin >> n >> q;
        for (int i = 0; i < W; ++i)
            cnt[i] = 0;
        for (int i = 1; i <= n; ++i)
            cin >> a[i], ++cnt[a[i]];
        solve();
        for (int i = 1, p, x; i <= q; ++i)
            cin >> p >> x, --cnt[a[p]], ++cnt[a[p] = x], solve();
        cout << "\n";
    }
}
