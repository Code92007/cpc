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
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
using namespace std;
const int N=3e5+10;
int t,n,m,u,v,ans[N];
bool vis[N];
vector<int>e[N];
// queue<int>q;
// void bfs(){
//     ans[1]=0;
//     q.push(1);
//     while(!q.empty()){
//         int u=q.front();
//         q.pop();
//         //printf("u:%d\n",u);
//         vis[u]=1;
//         for(auto &v:e[u]){
//             if(vis[v])continue;
//             if(ans[v]<=ans[u]){
//                 ans[v]=ans[u]+1;
//                 q.push(v);
//             }
//         }
//     }
// }
void dfs(int u,int w){
    ans[u]=w;
    vis[u]=1;
    for(auto &v:e[u]){
        if(vis[v])continue;
        dfs(v,w+1);
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,n){
            e[i].clear();
            vis[i]=0;
            ans[i]=0;
        }
        rep(i,1,m){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(1,0);
        //bfs();
        rep(i,1,n){
            printf("%d%c",ans[i]," \n"[i==n]);
        }
    }
    return 0;
}