#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int n;
vector<int> p;
vector<P> gauss;
set<P> ans;

// 找到 p = c^2 + d^2 的解
P f(int v) {
    for (int i = 1; i < v; ++i) {
        for (int j = 1; j < i; ++j) {
            if (i * i + j * j == v) {
                return P(i, j);
            }
        }
    }
    return P(-1, -1);
}

// 递归构造圆上的点
void dfs(int i, ll a, ll b) {
    if (ans.size() >= n) return; // 凑够 n 个即可提前剪枝（set还会去重，稍微多生成点没关系）
    
    // 递归终点：利用对称性将该点映射到四个象限
    if (i == p.size()) {
        ans.insert({a, b});
        ans.insert({a, -b});
        ans.insert({-a, b});
        ans.insert({-a, -b});
        return;
    }

    ll c = gauss[i].first;
    ll d = gauss[i].second;
    ll pi = p[i];

    // 选择 1：乘以素数 p_i 本身 (即 p_i + 0i)，模长变为原来的 p_i 倍
    dfs(i + 1, a * pi, b * pi);

    // 选择 2：乘以 (c + di)^2，其实部为 c^2 - d^2，虚部为 2cd。模长同样为原来的 p_i 倍
    ll u1 = c * c - d * d;
    ll v1 = 2 * c * d;
    dfs(i + 1, a * u1 - b * v1, a * v1 + b * u1);

    // 选择 3：乘以 (c - di)^2，其实部为 c^2 - d^2，虚部为 -2cd。模长同样为原来的 p_i 倍
    ll u2 = c * c - d * d;
    ll v2 = -2 * c * d;
    dfs(i + 1, a * u2 - b * v2, a * v2 + b * u2);
}

void sol() {
    cin >> n;
    
    // 收集前 6 个满足 p % 4 == 1 的素数，足以生成 >1000 个点
    int count = 0;
    for (int i = 5; count < 6; i += 4) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) { is_prime = false; break; }
        }
        if (is_prime) {
            p.push_back(i);
            gauss.push_back(f(i));
            count++;
        }
    }

    // 计算并固定我们的目标整数半径 R
    ll radius = 1;
    for (int x : p) radius *= x;

    // 从坐标 (1, 0) 开始，初始模长为 1
    dfs(0, 1, 0);

    // 格式第一步：一定要输出半径
    cout << radius << "\n";
    
    // 输出 n 个点
    int printed = 0;
    for (auto it = ans.begin(); it != ans.end() && printed < n; ++it, ++printed) {
        cout << it->first << " " << it->second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sol();
    return 0;
}