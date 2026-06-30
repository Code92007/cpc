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
typedef pair<int,int> P;
typedef array<int,3> A;
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
const int N=5e5+10,K=21;
int n,q,u,v,w,x,y;
int dep[N],st[N][K];
ll dis[N],ans[N],dp[N],dp2[N];
P a[N];
vector<P>e[N],ask[N];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    st[u][0]=fa;
    for(int i=1;i<20;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(auto &x:e[u]){
        int v=x.fi,w=x.se;
        if(v==fa)continue;
        dis[v]=dis[u]+w;
        dfs(v,u);
        ll z=dp[v]+w;
        if(z>=dp[u])dp2[u]=dp[u],dp[u]=z;
        else if(z>=dp2[u])dp2[u]=z;
    }
}
void dfs2(int u,int fa){
    for(auto &x:ask[u]){
        int id=x.fi,v=x.se;
        ans[id]=max(ans[id],2ll*dp[v]);
    }
    for(auto &x:e[u]){
        int v=x.fi,w=x.se;
        if(v==fa)continue;
        ll z1=dp[u],z2=dp[v];
        if(dp[v]+w==z1)dp[u]=dp2[u];
        dp[v]=max(dp[v],dp[u]+w);
        dfs2(v,u);
        dp[v]=z2,dp[u]=z1;
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=19;~i;i--){
        if(dep[st[u][i]]>=dep[v])u=st[u][i];
    }
    if(u==v)return u;
    for(int i=19;~i;i--){
        if(st[u][i]==st[v][i])continue;
        u=st[u][i];
        v=st[v][i];
    }
    return st[u][0];
}
ll cal(int u,int v){
    return dis[u]+dis[v]-2*dis[lca(u,v)];
}
int main(){
    sci(n),sci(q);
    rep(i,2,n){
        sci(u),sci(v),sci(w);
        e[u].pb(P(v,w));
        e[v].pb(P(u,w));
    }
    rep(i,1,q){
        sci(x),sci(y);
        a[i]=P(x,y);
        ask[x].pb(P(i,y));
        if(x!=y)ask[y].pb(P(i,x));
    }
    dfs(1,0);
    dfs2(1,0);
    rep(i,1,q){
        //printf("i:%d cal:%lld\n",i,cal(a[i].fi,a[i].se));
        ans[i]+=cal(a[i].fi,a[i].se);
        printf("%lld\n",ans[i]);
    }
    return 0;
}