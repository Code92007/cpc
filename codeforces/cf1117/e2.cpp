#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, int, int> pllii;
const int N = 2e5 + 5;
int t, n, len[N];
pii ans;
ll x;
vector<int> a[N], b[N];
vector<pllii> c;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    for (cin >> t; t; --t) {
        cin >> n >> x, c.clear(), ans = pii(0, -1);
        for (int i = 1, m; i <= n; ++i) {
            cin >> m, len[i] = 0;
            a[i].assign(m, 0), b[i].assign(m, 0);
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
            for (int j = 0; j < mV; ++j)
                cin >> b[i][j];
            ll x = 0, y = 0;
            for (int j = 0; j < m; ++j) {
                y = max(y, a[i][j] - x), x += b[i][j] - a[i][j];
                if (x > 0)
                    c.emplace_back(y, x, i, j + 1), x = 0;
            }
        }
        sort(c.begin(), c.end());
        for (auto [p, q, i, j] : c)
            if (x >= p)
                x += q, len[i] = max(len[i],j);
        for (int i = 1; i <= n; ++i) {
            int j = len[i];
            for (ll y = x; j < a[i].size() && y >= a[i][j]; ++j)
                y += b[i][j] - a[i][j];
            ans = max(ans, pii(j, -i));
        }
        cout << ans.first << " " << -ans.second << "\n";
    }
}