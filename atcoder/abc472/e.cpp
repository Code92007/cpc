//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
const int N=2e5+10;
int t,n,m,u,v,par[N],col[N],dep[N];
vector<int>e[N],ans;
bool vis[N];
bool dfs(int u,int c){
    vis[u]=1;
    col[u]=c;
    for(auto &v:e[u]){
        if(!vis[v]){
            dep[v]=dep[u]+1;
            par[v]=u;
            if(!dfs(v,-c))return 0;
        }
        else{
            printf("v:%d col:%d\n",v,col[v]);
            if(col[v]==c){
                for(int i=u,j=v;i!=j;){
                }
                return 0;
            }
        }
    }
    return 1;
}
void sol(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        e[i].clear();
        vis[i]=col[i]=0;
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(dfs(1,1)){
        puts("-1");
    }
    else{
        int sz=ans.size();
        printf("%d\n",sz);
        for(auto &v:ans){
            printf("%d ",v);
        }
        puts("");
        ans.clear();
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        sol();
    }
    return 0;
}