#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2 * n + 1, vector<int>(2 * n + 1, 0));
    for (int j = 1; j <= n; j++) {
        a[n][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        a[i][n] = n;
    }
    for (int j = n + 1; j <= 2 * n; j++) {
        a[n][j] = n * n;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        a[i][n] = n * n * n;
    }
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}