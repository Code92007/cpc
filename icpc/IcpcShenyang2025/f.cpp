#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        --x; --y;
        vector<vector<int>> g(n);
        vector<pair<int, int>> edges(m);
        for (auto &[u, v] : edges) {
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (find(g[x].begin(), g[x].end(), y) == g[x].end()) {
            cout << "Yes\n";
            for (auto [u, v] : edges) {
                if (u == x || u == y) swap(u, v);
                cout << u + 1 << ' ' << v + 1 << '\n';
            }
            continue;
        }

        // 删去 s-t 后找最短路；找不到说明 s-t 是桥。
        auto get_cycle = [&](int s, int t) {
            vector<int> pre(n, -1), c;
            queue<int> q;
            pre[s] = s;
            q.push(s);
            while (!q.empty() && pre[t] == -1) {
                int u = q.front(); q.pop();
                for (int v : g[u]) {
                    if ((u == s && v == t) || (u == t && v == s))
                        continue;
                    if (pre[v] != -1) continue;
                    pre[v] = u;
                    q.push(v);
                }
            }
            if (pre[t] == -1) return c;
            for (int u = t; u != s; u = pre[u]) c.push_back(u);
            c.push_back(s); // 按此顺序连起来，最后用 s->t 闭环。
            return c;
        };

        vector<int> cycle = get_cycle(x, y), seen(n);
        queue<int> q;
        seen[x] = seen[y] = 1;
        q.push(x); q.push(y);
        while (cycle.empty() && !q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (seen[v]) continue;
                cycle = get_cycle(u, v);
                if (!cycle.empty()) break;
                seen[v] = 1;
                q.push(v);
            }
        }
        if (cycle.empty()) {
            cout << "No\n";
            continue;
        }

        // 多源 BFS 求到环的距离。
        vector<int> d(n, -1), nxt(n, -1);
        queue<int> bfs;
        for (int i = 0; i < (int)cycle.size(); ++i) {
            int u = cycle[i];
            nxt[u] = cycle[(i + 1) % cycle.size()];
            d[u] = 0;
            bfs.push(u);
        }
        while (!bfs.empty()) {
            int u = bfs.front(); bfs.pop();
            for (int v : g[u]) {
                if (d[v] != -1) continue;
                d[v] = d[u] + 1;
                bfs.push(v);
            }
        }

        cout << "Yes\n";
        for (auto [u, v] : edges) {
            if (d[u] < d[v]) swap(u, v);
            if (d[u] == 0 && d[v] == 0 && nxt[u] != v) swap(u, v);
            cout << u + 1 << ' ' << v + 1 << '\n';
        }
    }
}