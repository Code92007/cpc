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
const int N=4e5+10,INF=0x3f3f3f3f;
int t,n,u,v,col[N],dp[N][2],ans[N];//0:3w-c,1:3c-w
char s[N];
vector<int>e[N];
void dfs(int u,int fa){
    if(col[u]){
        dp[u][0]=3;
        dp[u][1]=-1;
    }
    else{
        dp[u][0]=-1;
        dp[u][1]=3;
    }
    int x=dp[u][0],y=dp[u][1];
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        ans[u]=max(ans[u],dp[u][0]+dp[v][0]);
        ans[u]=max(ans[u],dp[u][1]+dp[v][1]);
        if(dp[v][0]+x>dp[u][0])dp[u][0]=x+dp[v][0];
        if(dp[v][1]+y>dp[u][1])dp[u][1]=y+dp[v][1];
    }
    ans[u]=max(ans[u],dp[u][0]);
    ans[u]=max(ans[u],dp[u][1]);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s+1);
        for(int i=1;i<=n;++i){
            col[i]=s[i]-'0';
            e[i].clear();
            ans[i]=-INF;
        }
        for(int i=2;i<=n;++i){
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1,0);
        for(int i=1;i<=n;++i){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
/*
3
8
00101110
1 2
1 3
3 4
3 5
5 6
5 7
7 8
2
01
1 2
2
00
1 2

1
2
00
1 2
*/