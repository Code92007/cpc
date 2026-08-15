//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define scll(a) scanf("%lld",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
//我的先手路径上除去两个端点不能有奇数个嘟噜的旁支 且两个端点剩余度均为偶数 换言之就是两个端点的度数是奇数 中间全是偶数 这样的路径数量
const int N=2e5+10;
vector<int>e[N];
int t,n,u,v;//1 10
ll ans,dp[N][2];
void dfs(int u,int fa){
    int w=SZ(e[u])%2;
    if(w==1)dp[u][0]=1;
    //printf("u:%d fa:%d w:%d\n",u,fa,w);
    for(auto &v:e[u]){
        if(v==fa)continue;
        //printf("v:%d\n",v);
        dfs(v,u);
        if(w==0){
            ans+=1ll*dp[u][1]*(dp[v][1]+dp[v][0]);
            dp[u][1]+=dp[v][1]+dp[v][0];
        }
        else{
            ans+=dp[v][1]+dp[v][0];
        }
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            e[i].clear();
            dp[i][0]=dp[i][1]=0;
        }
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        ans=0;
        dfs(1,0);
        ptlle(ans);
    }
    return 0;
}