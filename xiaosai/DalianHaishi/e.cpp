//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
#include<set>
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
typedef pair<int,int> P;
const int N=2e6+10;
int T,n,s,u,v,dp[N][4];
vector<int>e[N];
//每个点删不删 如果不删的话 每个儿子得是孤立点
//是孤立点且和儿子有边相连 是孤立点但和儿子无边相连
//dp[i][3](0:删 1:不删是孤立点且和儿子有边相连 2:不删是孤立点但和儿子无边相连 3:不删不是孤立点)的最小删点数
void dfs(int u,int fa){
    int son=0;
    dp[u][0]=1;dp[u][1]=dp[u][2]=dp[u][3]=0;
    int delta=0;//dp[u][1]:允许儿子最多有一个3
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        son++;
        dp[u][0]+=min(min(min(dp[v][0],dp[v][1]),dp[v][2]),dp[v][3]);
        dp[u][1]+=dp[v][0];
        delta=max(delta,dp[v][0]-dp[v][3]);
        dp[u][2]+=dp[v][0];
        dp[u][3]+=min(dp[v][0],dp[v][2]);
    }
    dp[u][1]-=delta;
    // rep(i,0,3){
    //     printf("u:%d i:%d dp:%d\n",u,i,dp[u][i]);
    // }
}
int main(){
    sci(T);
    while(T--){
        sci(n),sci(s);
        rep(i,1,n)e[i].clear();
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(s,0);    
        int ans=n;
        rep(i,0,3){
            ans=min(ans,dp[s][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}