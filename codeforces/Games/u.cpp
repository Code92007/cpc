//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define se second
#define pb push_back
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
const int N=4e4+10,M=32;
int u,v,n;
int dp[N][M];
char s[3][10]={"Stas","Masha","Missing"};
bool cal(int u,int v){
    ll res=1;
    if(u==1)return 0;
    rep(i,1,v){
        res*=u;
        if(res>=n)return 1;
    }
    return 0;
}
int dfs(int u,int v){
    int &ans=dp[u][v];
    if(~ans)return ans;
    if(cal(u,v))return ans=1;
    bool vis[3]={0,0,0};
    if(v==1 && cal(u,2)){
        int dis=n-u;
        dis%=2;
        if(dis==1)return ans=0;
        else return ans=1;
    }
    if(u==1 && (v>=30 || (1<<v)>=n)){
        return ans=2;
    }
    vis[dfs(u+1,v)]=1;
    vis[dfs(u,v+1)]=1;
    if(vis[0])return ans=1;
    else if(vis[2])return ans=2;
    return ans=0;
}
int main(){
    sci(u),sci(v),sci(n);
    memset(dp,-1,sizeof dp);
    int w=dfs(u,v);
    // rep(i,1,3){
    //     rep(j,1,3){
    //         printf("i:%d j:%d sg:%d\n",i,j,dfs(i,j));
    //     }
    // }
    // printf("w:%d\n",w);
    printf("%s\n",s[w]);
    return 0;
}