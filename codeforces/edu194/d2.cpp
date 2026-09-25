// International_River

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
typedef long long i64;
typedef pair<int, int> pii;

void solve() {
    int n; string s;
    cin >> n >> s;
    auto test = [&](int mx) {
        vector a(n + 1, vector<char>(9, 0));
        a[0][4] = 1;
        for(int i = 1; i <= n; i++) {
            char c = s[i - 1];
            for(int j = 0; j < 9; j++) {
                for(int k = 0; k < 9; k++) {
                    if(k != j && abs(k - j) <= mx) {
                        a[i][j] |= a[i - 1][k];
                    }
                }
            }
            if(c == '0' || c == '+') {
                for(int j = 0; j < 4; j++) a[i][j] = 0;
            }
            if(c == '0' || c == '-') {
                for(int j = 5; j < 9; j++) a[i][j] = 0;
            }
            if(c == '-' || c == '+') a[i][4] = 0;
        }
        for(auto x : a.back()) if(x) return true;
        return false;
    };
    for(int i = 1; i <= 4; i++) {
        if(test(i)) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
