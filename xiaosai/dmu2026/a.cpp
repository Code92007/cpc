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
typedef array<ll,3> A;
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
const int N=1e5+10,mod=998244353;
int t,n,m,dp[N];
vector<int>e[N];
int dfs(int u){
    if(u==n){
        return dp[u]=1;
    }
    if(~dp[u])return dp[u];
    dp[u]=0;
    for(auto &v:e[u]){
        dp[u]=(dp[u]+dfs(v))%mod;
    }
    return dp[u];
}
int main(){
    sci(t);
    while(t--){
        sci(n);sci(m);
        rep(i,1,n){
            dp[i]=-1;
            e[i].clear();
        }
        rep(i,1,m){
            int u,v;
            sci(u),sci(v);
            e[u].pb(v);
        }
        rep(i,1,n-1){
            dfs(i);
        }
        rep(i,1,n-1){
            printf("%d%c",dp[i]," \n"[i==n-1]);
        }
    }
    return 0;
}