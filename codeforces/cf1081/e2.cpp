#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
#define sci(a) scanf("%d",&(a))
#define pte(a) printf("%d\n",a)
const int N=1e6+10;

int t,n;
int a[N],b[N],cnt[N],now[N],need[N];
vector<pair<int,int>> g[N]; // to, edge_id
bool vis[N];
int parent[N], pedge[N];
vector<int> ans;

void dfs_tree(int root) {
    stack<int> stk;
    stk.push(root);
    parent[root] = 0;
    vis[root] = true;

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        for (auto [v, id] : g[u]) {
            if (v == parent[u] || vis[v]) continue;
            parent[v] = u;
            pedge[v] = id;
            vis[v] = true;
            stk.push(v);
        }
    }
}

bool dfs_adjust(int root) {
    vector<int> order;
    stack<int> stk;
    stk.push(root);
    parent[root] = 0;
    fill(vis, vis + n + 1, false); // 重新标记未访问

    while (!stk.empty()) {
        int u = stk.top();
        if (!vis[u]) {
            vis[u] = true;
            for (auto [v, id] : g[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                pedge[v] = id;
                stk.push(v);
            }
        } else {
            stk.pop();
            order.push_back(u);
        }
    }

    // 后序遍历处理
    for (int u : order) {
        for (auto [v, id] : g[u]) {
            if (v != parent[u]) continue;
            if (need[v] != 0) {
                ans.push_back(id);
                if (a[id] == v && b[id] == u) {
                    need[v]--;
                    need[u]++;
                } else if (a[id] == u && b[id] == v) {
                    need[u]--;
                    need[v]++;
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

bool solve() {
    rep(i,1,n) {
        if (cnt[i] % 2) return false;
        cnt[i] /= 2;
        need[i] = cnt[i] - now[i];
    }

    // 建图
    rep(i,1,n) {
        int u = a[i], v = b[i];
        if (u == v) continue; // 自环忽略
        g[u].pb({v, i});
        g[v].pb({u, i});
    }

    ans.clear();
    rep(i,1,n) vis[i] = false;

    rep(i,1,n) {
        if (!vis[i]) {
            dfs_tree(i);
        }
    }

    rep(i,1,n) vis[i] = false; // 重置vis用于adjust

    rep(i,1,n) {
        if (!vis[i]) {
            if (!dfs_adjust(i)) return false;
        }
    }

    // 统计每条边出现次数，只保留奇数次的边
    map<int,int> cnt_in_ans;
    for (int id : ans) cnt_in_ans[id]++;

    ans.clear();
    for (auto [id, c] : cnt_in_ans) {
        if (c % 2 == 1) ans.push_back(id);
    }
    sort(ans.begin(), ans.end());

    // 检查 need 是否归零
    rep(i,1,n) if (need[i] != 0) return false;

    return true;
}

int main() {
    sci(t);
    while (t--) {
        sci(n);
        rep(i,1,n) {
            cnt[i] = now[i] = 0;
            g[i].clear();
        }
        rep(i,1,n) sci(a[i]), cnt[a[i]]++;
        rep(i,1,n) sci(b[i]), cnt[b[i]]++;
        rep(i,1,n) now[a[i]]++;

        if (!solve()) {
            puts("-1");
        } else {
            printf("%d\n", (int)ans.size());
            for (int x : ans) printf("%d ", x);
            puts("");
        }
    }
    return 0;
}