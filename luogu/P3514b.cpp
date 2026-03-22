#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> P;
const int N = 1e6 + 10;

char s[N];
int sum[N];
P a[N * 2];
int mx[2] = {-1, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        if(s[i] == 'W') sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1] + 2;
    }
    int l = -1, r = -1;
    mx[sum[n] & 1] = sum[n];
    auto &k = mx[(sum[n] & 1) ^ 1];
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'W') {
            if(sum[n] - sum[i] >= k) {
                k = sum[n] - sum[i], l = i + 1, r = n;
            }
            break;
        }
    }
    for(int i = n; i; i--) {
        if(s[i] == 'W') {
            if(sum[i - 1] >= k) {
                k = sum[i - 1], l = 1, r = i - 1;
            }
            break;
        }
    }
    // cerr << k << ' ' << l << ' ' << r << '\n';
    a[k] = {l, r};
    for(int i = k - 2; i > 0; i -= 2) {
        if(s[l] == 'T') l++;
        else if(s[r] == 'T') r--;
        else l++, r--;
        a[i] = {l, r};
    }
    a[sum[n]] = {1, n};
    l = 1, r = n;
    for(int i = sum[n] - 2; i > 0; i -= 2) {
        if(s[l] == 'T') l++;
        else if(s[r] == 'T') r--;
        else l++, r--;
        a[i] = {l, r};
    }
    while(m--) {
        int x;
        cin >> x;
        if(x > mx[x & 1]) cout << "NIE\n";
        else cout << a[x].first << ' ' << a[x].second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}