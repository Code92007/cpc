#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<random>
using namespace std;
#define ll long long
#define ull unsigned ll
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef double db;
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
const int N = 1e6+10, mod = 998244353;
int n,m,v,dp[N],sum[N];
int main(){
    scanf("%d%d",&n,&m);
    dp[0]=sum[0]=1;
    rep(i,1,m)sum[i]=1;
    rep(i,1,n){
        sci(v);
        v=min(v,m);
        per(j,m,0){
            int w=j-v-1;
            dp[j]=sum[j];
            if(w>=0)dp[j]=(dp[j]-sum[w]+mod)%mod;
        }
        rep(j,0,m){
            if(j==0)sum[j]=dp[j];
            else sum[j]=(sum[j-1]+dp[j])%mod;
        }
    }
    pte(dp[m]);
    return 0;
}