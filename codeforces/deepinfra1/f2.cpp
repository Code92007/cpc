// International_River

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
typedef long long i64;
typedef pair<int, int> pii;

const int N = 2e5 + 10;
int a[N], mx[N][20], mylg[N], n;

int query(int l, int r) {
    int s = mylg[r - l + 1];
    return max(mx[l][s], mx[r - (1 << s) + 1][s]);
}

void getst() {
    for(int i = 1; i <= n; i++) {
        mx[i][0] = a[i];
    }
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        }
    }
}

bool check0() {
    getst();
    vector<int> vis(n + 2, 0);
    vector<pii> v;
    for(int i = 1; i <= n; i++) {
        v.emplace_back(a[i], i);
    }
    sort(all(v));
    for(int i = 1; i < v.size(); i++) {
        if(v[i].first != v[i - 1].first) continue;
        int l = v[i - 1].second, r = v[i].second;
        if(l + 1 == r || query(l + 1, r - 1) < a[l]) {
            vis[l]++; vis[r + 1]--;
        }
    }
    for(int i = 1; i <= n; i++) {
        vis[i] += vis[i - 1];
        if(vis[i] == 0) return false;
    }
    return true;
}

pii check1() {
    getst();
    int x = query(1, n);
    int p = 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] == x) p = i;
    }
    int t = a[1];
    a[1] = x;
    if(check0()) return {1, x};
    else a[1] = t;
    t = a[n];
    a[n] = x;
    if(check0()) return {n, x};
    else a[n] = t;
    a[p] = 1;
    if(check0()) return {p, 1};
    else return {-1, -1};
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(check0()) {
        cout << 0 << endl;
    } else {
        pii p = check1();
        if(p.first != -1) {
            cout << 1 << endl;
            cout << p.first << ' ' << p.second << endl;
        } else {
            cout << 2 << endl;
            cout << 1 << ' ' << 1000000000 << endl;
            cout << n << ' ' << 1000000000 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for(int i = 2; i < N; i++) {
        mylg[i] = mylg[i / 2] + 1;
    }
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
