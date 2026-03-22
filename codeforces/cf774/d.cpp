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
const int N=2e5+10;
int n,u,v,dp[N][2],res[N];
ll cost[N][2];
vector<int>e[N];
void dfs(int u,int fa){
    dp[u][1]=1;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        dp[u][1]+=dp[v][0];
        cost[u][1]+=cost[v][0];
        if(dp[v][0]>dp[v][1]){
            dp[u][0]+=dp[v][0];
            cost[u][0]+=cost[v][0];
        }
        else if(dp[v][0]<dp[v][1]){
            dp[u][0]+=dp[v][1];
            cost[u][0]+=cost[v][1];
        }
        else{
            dp[u][0]+=dp[v][0];
            cost[u][0]+=min(cost[v][0],cost[v][1]);
        }
    }
    cost[u][0]++;
    cost[u][1]+=SZ(e[u]);
}
void dfs2(int u,int fa,int ch){
    int nex;
    if(ch==1)res[u]=SZ(e[u]);
    else res[u]=1;
    for(auto &v:e[u]){
        if(v==fa)continue;
        if(ch==1)dfs2(v,u,0);
        else{
            if(dp[v][0]>dp[v][1])dfs2(v,u,0);
            else if(dp[v][1]>dp[v][0])dfs2(v,u,1);
            else if(cost[v][0]<cost[v][1])dfs2(v,u,0);
            else dfs2(v,u,1);
        }
    }
}
int main(){
    sci(n);
    rep(i,2,n){
        sci(u),sci(v);
        e[u].pb(v);
        e[v].pb(u);
    }
    if(n<=2){
        printf("%d %d\n",n,n);
        rep(i,1,n)printf("%d ",1);
        return 0;
    }
    int rt=1;
    rep(i,1,n){
        if(SZ(e[i])>=2){
            rt=i;
            break;
        }
    }
    dfs(rt,0);
    int ch;
    if(dp[rt][0]>dp[rt][1])ch=0;
    else if(dp[rt][1]>dp[rt][0])ch=1;
    else if(cost[rt][0]<cost[rt][1])ch=0;
    else ch=1;
    printf("%d %lld\n",dp[rt][ch],cost[rt][ch]);
    dfs2(rt,0,ch);
    rep(i,1,n){
        printf("%d%c",res[i]," \n"[i==n]);
    }
    return 0;
}