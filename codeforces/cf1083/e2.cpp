#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> T(n);
        for (int i = 0; i < n; i++) cin >> T[i];
        
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) isPal[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (T[l] == T[r] && (len == 2 || isPal[l+1][r-1]))
                    isPal[l][r] = true;
            }
        }
        
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPal[j][i-1]) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                } else {
                    dp[i] = (dp[i] + dp[j] * 2) % MOD;
                }
            }
        }
        
        cout << dp[n] << "\n";
    }
    
    return 0;
}