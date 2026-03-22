//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

int n;
vector<int> g[N];
ll a[N], sum[N], f[N], ans[N];
int depth[N], in[N], out[N], dfs_clock;
int parent[N];

// best inside subtree
int best_in[N], best_in_node[N];
int second_in[N], second_in_node[N];

// best outside subtree (from parent side)
int best_out[N], best_out_node[N];
int second_out[N], second_out_node[N]; // 用于排除情况

ll total_sum;

void dfs1(int u, int p) {
    parent[u] = p;
    sum[u] = a[u];
    in[u] = ++dfs_clock;

    best_in[u] = depth[u];
    best_in_node[u] = u;
    second_in[u] = -1;
    second_in_node[u] = -1;

    for (int v : g[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs1(v, u);
        sum[u] += sum[v];

        if (best_in[v] > best_in[u]) {
            second_in[u] = best_in[u];
            second_in_node[u] = best_in_node[u];
            best_in[u] = best_in[v];
            best_in_node[u] = best_in_node[v];
        } else if (best_in[v] > second_in[u]) {
            second_in[u] = best_in[v];
            second_in_node[u] = best_in_node[v];
        }
    }
    out[u] = dfs_clock;
}

void dfs2(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        f[v] = f[u] + total_sum - 2 * sum[v];
        dfs2(v, u);
    }
}

void dfs3(int u, int p, int out_max, int out_max_node, int out_second, int out_second_node) {
    best_out[u] = out_max;
    best_out_node[u] = out_max_node;
    second_out[u] = out_second;
    second_out_node[u] = out_second_node;

    for (int v : g[u]) {
        if (v == p) continue;

        int new_out_max, new_out_max_node;
        int new_out_second, new_out_second_node;

        // 计算传给 v 的 out_max 和 out_second
        if (best_in_node[u] == best_in_node[v]) {
            // u 的最大 depth 节点在 v 的子树内
            new_out_max = max(second_in[u], out_max);
            new_out_max_node = (second_in[u] > out_max) ? second_in_node[u] : out_max_node;

            // 次大：从 second_in[u] 和 out_max 中选较小的那个（用于当 new_out_max 不可用时）
            if (second_in[u] > out_max) {
                new_out_second = max(out_max, second_in[u] < best_in[u] ? second_in[u] : -1);
                new_out_second_node = (out_max > second_in[u]) ? out_max_node : second_in_node[u];
            } else {
                new_out_second = max(second_in[u], out_second);
                new_out_second_node = (second_in[u] > out_second) ? second_in_node[u] : out_second_node;
            }
        } else {
            new_out_max = max(best_in[u], out_max);
            new_out_max_node = (best_in[u] > out_max) ? best_in_node[u] : out_max_node;

            // 次大
            if (best_in[u] > out_max) {
                new_out_second = max(out_max, second_in[u]);
                new_out_second_node = (out_max > second_in[u]) ? out_max_node : second_in_node[u];
            } else {
                new_out_second = max(best_in[u], out_second);
                new_out_second_node = (best_in[u] > out_second) ? best_in_node[u] : out_second_node;
            }
        }

        dfs3(v, u, new_out_max, new_out_max_node, new_out_second, new_out_second_node);
    }
}

void solve() {
    // 预处理每个节点 u 的贡献
    vector<vector<pair<int, ll>>> updates(n + 1);

    for (int u = 1; u <= n; u++) {
        // 对每个 u，找可用的 v 的 depth
        int use_depth;
        int best_global_depth = max(best_in[u], best_out[u]);
        int best_global_node = (best_in[u] > best_out[u]) ? best_in_node[u] : best_out_node[u];

        int second_global_depth;
        if (best_in[u] > best_out[u]) {
            second_global_depth = max(second_in[u], best_out[u]);
        } else {
            second_global_depth = max(best_in[u], second_out[u]);
        }

        // 如果 best_global_node 不在 u 子树内，用它，否则用 second
        if (!(in[u] <= in[best_global_node] && out[best_global_node] <= out[u])) {
            use_depth = best_global_depth;
        } else {
            use_depth = second_global_depth;
        }

        if (use_depth == -1) continue;

        ll gain = (use_depth - depth[u] + 1) * sum[u];
        if (gain <= 0) continue;

        // u 能贡献给它的所有祖先 r
        int r = parent[u];
        while (r != 0) {
            updates[r].emplace_back(u, gain);
            r = parent[r];
        }
    }

    // 计算每个 r 的答案
    for (int r = 1; r <= n; r++) {
        ll max_gain = 0;
        for (auto [u, gain] : updates[r]) {
            // 检查 u 是否在 r 的子树内（应该已经在祖先关系里保证了）
            if (in[r] <= in[u] && out[u] <= out[r]) {
                max_gain = max(max_gain, gain);
            }
        }
        ans[r] = f[r] + max_gain;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        total_sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            total_sum += a[i];
            g[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs_clock = 0;
        depth[1] = 0;
        dfs1(1, 0);

        f[1] = 0;
        for (int i = 2; i <= n; i++) {
            f[1] += (ll)a[i] * depth[i];
        }

        dfs2(1, 0);

        dfs3(1, 0, -1, -1, -1, -1);

        solve();

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " \n"[i == n];
        }
    }
    return 0;
}