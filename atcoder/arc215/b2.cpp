#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void sol() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m + 1);
    vector<vector<int>> pos(n, vector<int>());
    
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        a[i]--;
        pos[a[i]].push_back(i);
    }
    
    vector<vector<pair<int, int>>> e(m + 1);
    int edge_id = 0;
    
    for (int j = 1; j <= m; ++j) {
        ++edge_id;
        e[j].push_back({j - 1, edge_id});
        e[j - 1].push_back({j, edge_id});
    }
    
    for (int i = 0; i < n; ++i) {
        int x = pos[i][0], y = pos[i][1];
        ++edge_id;
        e[x - 1].push_back({y - 1, edge_id});
        e[y - 1].push_back({x - 1, edge_id});
    }
    
    vector<bool> vis(edge_id + 1, false);
    vector<int> color(m + 1, -1);
    vector<int> edge_u(edge_id + 1), edge_v(edge_id + 1);
    vector<int> edge_path;
    
    function<void(int)> dfs = [&](int u) {
        while (!e[u].empty()) {
            auto [v, id] = e[u].back();
            e[u].pop_back();
            if (vis[id]) continue;
            vis[id] = true;
            edge_u[id] = u;
            edge_v[id] = v;
            dfs(v);
            edge_path.push_back(id);
        }
    };
    
    dfs(0);
    reverse(edge_path.begin(), edge_path.end());
    
    color[0] = 0;
    for (int id : edge_path) {
        int u = edge_u[id], v = edge_v[id];
        if (color[v] == -1) color[v] = color[u] ^ 1;
    }
    
    auto count_dividers = [&](const vector<int>& col) {
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
            if ((col[i] ^ col[i - 1]) == 1) cnt++;
        return cnt;
    };
    
    if (count_dividers(color) > n) {
        for (int i = 0; i <= m; ++i) color[i] ^= 1;
    }
    
    vector<int> res;
    for (int i = 1; i <= m; ++i)
        if ((color[i] ^ color[i - 1]) == 1)
            res.push_back(i);
    
    cout << res.size() << "\n";
    for (int i = 0; i < (int)res.size(); ++i) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}

int main() {
    fast();
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}