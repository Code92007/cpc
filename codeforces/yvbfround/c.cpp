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
const int N=1e5+10;
int t,n,m,u,v,dp[N][2],now;
vector<int>e[N];
bool vis[N];
void dfs(int u,int anc){
    dp[u][0]=0;
    dp[u][1]=1;
    int son=-1;
    vis[u]=1;
    for(auto &v:e[u]){
        if(vis[v])continue;
        dfs(v,anc);
        son=v;
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][0],dp[v][1]);
    }
    if(u==anc){
        if(dp[u][1]<=dp[u][0])now=u;
        else now=son;
    }
}
void sol(){
    rep(i,1,n){
        e[i].clear();
        vis[i]=0;
        dp[i][0]=dp[i][1]=0;
    }
    rep(i,1,m){
        sci(u),sci(v);
        e[u].pb(v);
        e[v].pb(u);
    }
    if(!m){
        rep(i,2,n){
            printf("%d %d\n",1,i);
        }
        return;
    }
    vector<int>lone;
    int las=-1;
    rep(i,1,n){
        if(!vis[i]){
            if(!SZ(e[i])){
                lone.pb(i);
                continue;
            }
            dfs(i,i);
            if(~las)printf("%d %d\n",las,now);
            if(las==-1)las=now;
        }
    }
    for(auto &v:lone){
        printf("%d %d\n",las,v);
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        sol();
    }
    return 0;
}