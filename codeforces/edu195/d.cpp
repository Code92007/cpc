//#include<bits/stdc++.h>
#include<iostream>
#include<map>
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
const int N=3e5+10;
int t,n,m,u,v,sz[N],edg,leaf;
vector<int>e[N];
bool vis[N];
void dfs(int u,int fa){
    vis[u]=1;
    if(SZ(e[u])==1)leaf++;
    for(auto &v:e[u]){
        if(v==fa)continue;
        //printf("u:%d v:%d\n",u,v);
        edg++;
        if(vis[v])continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,n){
            e[i].clear();
            vis[i]=0;
            sz[i]=1;
        }
        rep(i,1,m){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        int ans=1;
        rep(i,1,n){
            if(!vis[i]){
                edg=leaf=0;
                dfs(i,0);
                if(sz[i]==1)ans=0;
                else if(sz[i]==2 || sz[i]==leaf+1)ans*=2;
                else if(sz[i]==3){
                    //printf("edg:%d\n",edg);
                    if(edg>=3)ans*=3;
                    else ans*=2;
                }
                else{
                    ans*=3;
                }
                ans=min(ans,3);
            }
        }
        if(!ans)puts("Brain Melt");
        else if(ans>=3)puts("Many");
        else puts("2");
    }
    return 0;
}
//0101 1101 0100
//010 