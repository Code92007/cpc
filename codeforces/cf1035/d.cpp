//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
const int N=5005;
int t,n,mod,dp[N],f[N][N],g[N][N];
/*
    dp[i]表示前i步的总方案 
    枚举第i步的决策 不取 从dp[i-1]转移而来 
    取 枚举[1,i]的任意一个j 取j 从f[i-1][j]*j转移而来
    f[i][j]表示前i步里没有移走第j个数的方案
    g[i][j]表示前i步里移走了第j个数的方案 
*/
void add(int &x,int y){
    x=(x+y)%mod;
}
int sol(){
    sci(n),sci(mod);
    rep(i,0,n+5){
        dp[i]=0;
        rep(j,0,n+5){
            f[i][j]=g[i][j]=0;
        }
    }
    dp[0]=1;
    rep(j,1,n){
        f[0][j]=dp[0];
    }
    rep(i,1,n){
        add(dp[i],dp[i-1]);//不移
        rep(j,1,i){
            add(dp[i],1ll*f[i-1][j]*j%mod);
            g[i][j]=(1ll*g[i-1][j]*(i+1)%mod+1ll*f[i-1][j]*j%mod)%mod;
            //f[i][j]=1ll*f[i-1][j]*(i-j+1)%mod;
        }
        rep(j,1,n){
            f[i][j]=(dp[i]+mod-g[i][j])%mod;
        }
        // rep(j,1,n){
        //     printf("i:%d j:%d dp:%d f:%d g:%d\n",i,j,dp[i],f[i][j],g[i][j]);
        // }
    }
    return dp[n];
}
int main(){
    sci(t);
    while(t--){
        pte(sol());
    }
    return 0;
}
/*
[0,0],[0,1],[0,2],[1,0],[1,1],[1,2]
没
[1] [2]
[2]
[1]
[1,2]
[1,2]

没
[1]*2
[2]*2
[1,2]*2

[0,0]
[0,1]
[1,0]
[0,2]*2
[1,2]*2

[0]
[1]

[0,0]
[1,0]
[0,1]
[0,2]*2
*/
//dp[i]表示前i步的总方案 
// 枚举第i步的决策 不移 从dp[i-1]转移而来 
// 移动 移动[1,i]的任意一个j 从f[i-1][j]转移而来
//f[i][j]表示前i步里没有移走第j个数的方案
//g[i][j]表示前i步里移走了第j个数的方案 
//i<j时，g[i][j]只能为0
//i>=j 从>=j的步数里 取ai∈[1,j]才有贡献 g[3][2] 第二步ai∈{1,2} 第三步ai∈{1,2}
//容斥一下 用前i步的 减掉移走第j个数的方案 那就枚举一下是第几步移走的