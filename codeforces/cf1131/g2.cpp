//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
const int N=2e5+10,mod=998244353;
int t,n,u,v,ans,x[N],y[N],b[N],c[N],dep[N];
vector<int>e[N];
bool dfs(int u,int fa,int d,int w){
    b[u]=x[u]^y[u]^c[u];
    if(dep[d]==-1){
        dep[d]=b[u];
        if(b[u])ans=(ans+w%mod)%mod;
    }
    else if(dep[d]!=b[u])return 0;
    int add=(x[u]+b[u]+c[u])/2;
    for(auto &v:e[u]){
        if(v==fa)continue;
        c[v]=add;
        if(!dfs(v,u,d+1,2ll*w%mod))return 0;
    }
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,0,n){
            e[i].clear();
            dep[i]=-1;
            c[i]=0;
        }
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        rep(i,1,n){
            scanf("%1d",&x[i]);
        }
        rep(i,1,n){
            scanf("%1d",&y[i]);
        }
        ans=0;
        if(!dfs(1,0,0,1))puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}