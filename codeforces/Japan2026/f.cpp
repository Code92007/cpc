#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Rect { ll a, b, c, d; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, u, v;
    while (cin >> n >> u >> v && (n || u || v)) {
        int m; 
        cin >> m;
        vector<Rect> r(m);
        vector<ll> x{1, n, u}, y{1, n, v};
        for (auto &[a, b, c, d] : r) {
            cin >> a >> b >> c >> d;
            if (a > 1) x.push_back(a - 1);
            if (b < n) x.push_back(b + 1);
            if (c > 1) y.push_back(c - 1);
            if (d < n) y.push_back(d + 1);
        }
        sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
        sort(y.begin(), y.end()); y.erase(unique(y.begin(), y.end()), y.end());

        int X = x.size(), Y = y.size(), N = X * Y;
        auto id = [Y](int i, int j) { 
            return i * Y + j; 
        };
        auto clear = [&](ll x1, ll y1, ll x2, ll y2) {
            for (auto [a, b, c, d] : r) {
                bool hit = x1 == x2
                    ? a <= x1 && x1 <= b && max(y1, c) <= min(y2, d)
                    : c <= y1 && y1 <= d && max(x1, a) <= min(x2, b);
                if (hit) return false;
            }
            return true;
        };

        vector<vector<pair<int, ll>>> g(N);
        auto add = [&](int a, int b, ll w) {
            g[a].push_back({b, w}); 
            g[b].push_back({a, w});
        };
        for (int i = 0; i < X; ++i) 
            for (int j = 0; j < Y; ++j) {
                if (i + 1 < X && clear(x[i], y[j], x[i + 1], y[j]))
                    add(id(i, j), id(i + 1, j), x[i + 1] - x[i]);
                if (j + 1 < Y && clear(x[i], y[j], x[i], y[j + 1]))
                    add(id(i, j), id(i, j + 1), y[j + 1] - y[j]);
        }

        int sx = lower_bound(x.begin(), x.end(), u) - x.begin();
        int sy = lower_bound(y.begin(), y.end(), v) - y.begin();
        const ll INF = 1LL << 62;
        vector<ll> dis(N, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dis[id(sx, sy)] = 0; 
        pq.push({0, id(sx, sy)});
        while (!pq.empty()) {
            auto [d, p] = pq.top(); 
            pq.pop();
            if (d != dis[p]) continue;
            for (auto [to, w] : g[p]) {
                if (dis[to] > d + w) {
                    dis[to] = d + w;
                    pq.push({dis[to], to});
                }
            }
        }

        int q; 
        cin >> q;
        while (q--) {
            ll s, t; 
            cin >> s >> t;
            int xi = lower_bound(x.begin(), x.end(), s) - x.begin();
            int yi = lower_bound(y.begin(), y.end(), t) - y.begin();
            ll ans = INF;
            for (int i : {xi - (x[xi] != s), xi})
                for (int j : {yi - (y[yi] != t), yi})
                    ans = min(ans, dis[id(i, j)] + abs(s - x[i]) + abs(t - y[j]));
            if (ans == INF) cout << "no\n";
            else cout << ans << '\n';
        }
    }
}