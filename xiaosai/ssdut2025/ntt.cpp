#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
using namespace std;

const long long mod = 998244353;
const long long g = 3; // 原根

long long power(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void ntt(vector<long long>& a, int inv) {
    int n = a.size();
    if(n == 1) return;
    
    vector<long long> a0(n/2), a1(n/2);
    for(int i = 0; i < n/2; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    
    ntt(a0, inv);
    ntt(a1, inv);
    
    long long wn = power(g, (mod-1)/n, mod);
    if(inv) wn = power(wn, mod-2, mod);
    
    long long w = 1;
    for(int i = 0; i < n/2; i++) {
        long long t = a1[i] * w % mod;
        a[i] = (a0[i] + t) % mod;
        a[i+n/2] = (a0[i] - t + mod) % mod;
        w = w * wn % mod;
    }
}

vector<long long> multiply(vector<long long> a, vector<long long> b) {
    int result_len = a.size() + b.size() - 1;
    int n = 1;
    while(n < result_len) n <<= 1;
    
    a.resize(n); b.resize(n);
    ntt(a, 0); ntt(b, 0);
    
    for(int i = 0; i < n; i++) {
        a[i] = a[i] * b[i] % mod;
    }
    
    ntt(a, 1);
    
    long long inv_n = power(n, mod-2, mod);
    for(int i = 0; i < n; i++) {
        a[i] = a[i] * inv_n % mod;
    }
    
    a.resize(result_len);
    return a;
}

int main(){
    int t, n, k, v;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d %d", &n, &k);
        
        vector<int> vis(n+1, 0);
        vector<long long> f(n+1, 0), dp(n+1, 0);
        
        for(int i = 0; i < k; i++) {
            scanf("%d", &v);
            vis[v] = 1;
        }
        
        f[1] = 1;
        dp[1] = 1;
        
        // 对每个j迭代
        for(int j = 1; j < n; j++) {
            vector<long long> prev_dp(n+1), poly_f(n+1);
            
            // 复制前一层的dp值
            for(int i = 1; i <= n; i++) {
                prev_dp[i] = dp[i];
            }
            for(int i = 1; i <= n; i++) {
                poly_f[i] = f[i];
            }
            
            // 使用NTT计算卷积
            vector<long long> conv = multiply(prev_dp, poly_f);
            
            // 更新dp值（注意边界条件）
            for(int i = 2; i <= n; i++) {
                dp[i] = conv[i];
                if(vis[i]) {
                    f[i] = (f[i] + dp[i]) % mod;
                }
            }
        }
        
        printf("%lld\n", f[n]);
    }
    
    return 0;
}