#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 500005;

// 存储向下分支的长度和对应的子节点编号
struct DownPath {
    ll val;
    int child;
};

DownPath down_p[N][3];
ll up_arr[N];
int st[N][20];
ll max_V[N][20];
int dep[N];
ll dep_w[N]; // 带权深度，用于算真实 dis(x, y)
vector<pair<int, ll>> adj[N];

// 第一遍 DFS：求向下前三大分支，以及倍增祖先
void dfs1(int u, int p) {
    dep[u] = dep[p] + 1;
    st[u][0] = p;
    for (int i = 1; i < 20; i++) {
        st[u][i] = st[st[u][i - 1]][i - 1];
    }
    // 初始距离为 0 (代表停在原地)
    down_p[u][0] = {0, 0}; down_p[u][1] = {0, 0}; down_p[u][2] = {0, 0};

    for (auto& edge : adj[u]) {
        int v = edge.first;
        ll w = edge.second;
        if (v == p) continue;
        dep_w[v] = dep_w[u] + w;
        dfs1(v, u);

        ll val = down_p[v][0].val + w;
        // 维护前三大分支
        if (val >= down_p[u][0].val) {
            down_p[u][2] = down_p[u][1];
            down_p[u][1] = down_p[u][0];
            down_p[u][0] = {val, v};
        } else if (val >= down_p[u][1].val) {
            down_p[u][2] = down_p[u][1];
            down_p[u][1] = {val, v};
        } else if (val > down_p[u][2].val) {
            down_p[u][2] = {val, v};
        }
    }
}

// 第二遍 DFS：求向上的最大分支，并初始化倍增的底层 max_V
void dfs2(int u, int p) {
    for (auto& edge : adj[u]) {
        int v = edge.first;
        ll w = edge.second;
        if (v == p) continue;

        ll max_other_down = 0;
        if (down_p[u][0].child == v) {
            max_other_down = down_p[u][1].val;
        } else {
            max_other_down = down_p[u][0].val;
        }

        up_arr[v] = max(up_arr[u], max_other_down) + w;
        up_arr[v] = max(up_arr[v], 0ll); // 最小是停在 v

        // 从 v 看向 u，u 往旁侧的最长分支
        max_V[v][0] = max_other_down; 
        dfs2(v, u);
    }
}

// 建立 max_V 的倍增表
void build_doubling(int n) {
    for (int i = 1; i < 20; i++) {
        for (int u = 1; u <= n; u++) {
            int p_node = st[u][i - 1];
            if (p_node != 0) {
                max_V[u][i] = max(max_V[u][i - 1], max_V[p_node][i - 1]);
            } else {
                max_V[u][i] = max_V[u][i - 1];
            }
        }
    }
}

int get_lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (dep[u] - (1 << i) >= dep[v]) u = st[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (st[u][i] != st[v][i]) {
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}

// 核心查询函数
ll solve_query(int x, int y) {
    if (x == y) return 2ll * max(down_p[x][0].val, up_arr[x]);

    int lca_xy = get_lca(x, y);
    ll dist_xy = dep_w[x] + dep_w[y] - 2ll * dep_w[lca_xy];
    ll max_branch = 0;
    int cx = 0, cy = 0; // 记录 x 和 y 所在 lca 的直属子节点

    // 爬升 x 分支
    if (x != lca_xy) {
        max_branch = max(max_branch, down_p[x][0].val); // x 自身的向下分支
        int curr = x;
        for (int i = 19; i >= 0; i--) {
            if (dep[curr] - (1 << i) > dep[lca_xy]) {
                max_branch = max(max_branch, max_V[curr][i]);
                curr = st[curr][i];
            }
        }
        cx = curr; // 停在 lca 正下方
    }

    // 爬升 y 分支
    if (y != lca_xy) {
        max_branch = max(max_branch, down_p[y][0].val);
        int curr = y;
        for (int i = 19; i >= 0; i--) {
            if (dep[curr] - (1 << i) > dep[lca_xy]) {
                max_branch = max(max_branch, max_V[curr][i]);
                curr = st[curr][i];
            }
        }
        cy = curr;
    }

    // 处理顶端 LCA 的旁侧分支
    max_branch = max(max_branch, up_arr[lca_xy]); // 往上的分支
    for (int i = 0; i < 3; i++) {
        int child = down_p[lca_xy][i].child;
        // 避开走向 x 和走向 y 的子树
        if (child != cx && child != cy) { 
            max_branch = max(max_branch, down_p[lca_xy][i].val);
        }
    }

    return dist_xy + 2ll * max_branch;
}

int main() {
    // 优化 IO，防超时
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    for (int i = 1; i < n; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs1(1, 0);
    up_arr[1] = 0;
    dfs2(1, 0);
    build_doubling(n);

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << solve_query(x, y) << "\n";
    }

    return 0;
}