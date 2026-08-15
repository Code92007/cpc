#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
typedef long long i64;
typedef pair<int, int> pii;

void solve() {
    string s; cin >> s >> s;
    vector dp(256, vector(8, string()));
    int cnt[10] = {};
    for(char ch : s) {
        if(ch == '0' || ch == '9') continue;
        int c = ch - '0';
        if(c!=3 && c!=6){
            if(++cnt[c] >= 9) continue;
            cnt[3]=cnt[6]=0;
        }
        else{
            if(++cnt[c] >= 3) continue;
        }
        for(int mask = 255; mask >= 0; mask--) {
            for(int pre = 7; pre >= 0; pre--) {
                if(dp[mask][pre].empty()) continue;
                int new_pre = (pre + 1 + c) % 9;
                if(new_pre-- == 0) continue;
                int new_mask = mask | (1 << new_pre);
                if(new_mask == mask) continue;
                if(dp[new_mask][new_pre].length() < dp[mask][pre].length() + 1) {
                    dp[new_mask][new_pre] = dp[mask][pre] + ch;
                }
            }
        }
        if(dp[1 << (c - 1)][c - 1].empty()) {
            dp[1 << (c - 1)][c - 1] += ch;
        }
    }
    string ans;
    for(auto &v : dp) {
        for(auto &x : v) {
            if(ans.length() < x.length()) ans = x;
        }
    }
    cout << ans.length();
    for(int i = 0, p = 0; i < s.length() && p < ans.length(); i++) {
        if(ans[p] == s[i]) {
            cout << " " << i + 1;
            p += 1;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
