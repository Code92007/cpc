//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
typedef pair<int,int> P;
const int N=2e5+10,INF=0x3f3f3f3f,mod=998244353;
int n,m,f[N],g[N],dp[N],pre[N];
vector<P>e[N];
queue<int>q[N];
vector<int>tmp[10];
bool vis[N];
//idea: 用rank小的先bfs，rank相同时在一个队列里，钦定下一位从1到9增序控制
int main(){
    scanf("%d%d",&n,&m);
    memset(dp,-1,sizeof dp);
    memset(f,INF,sizeof f);
    memset(g,INF,sizeof g);
    for(int i=1;i<=m;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[a].push_back(P(b,c));
    }
    q[1].push(1);
    f[1]=dp[1]=pre[1]=0;
    int tot=1;
    for(int i=1;i<=tot;++i){
        while(!q[i].empty()){
            int u=q[i].front();
            q[i].pop();
            if(vis[u])continue;
            vis[u]=1;
            for(auto &x:e[u]){
                int v=x.first,w=x.second;
                if(f[v]==INF || (f[v]==f[u]+1 && i==pre[v] && w<g[v])){
                    f[v]=f[u]+1;
                    pre[v]=i;
                    g[v]=w;
                    dp[v]=(10ll*dp[u]+w)%mod;
                    tmp[w].push_back(v);
                }
            }
        }
        for(int j=1;j<=9;++j){
            if(tmp[j].empty())continue;
            ++tot;
            for(auto &v:tmp[j]){
                q[tot].push(v);
            }
            tmp[j].clear();
        }
    }
    for(int i=2;i<=n;++i){
        printf("%d\n",dp[i]);
    }
    return 0;
}
