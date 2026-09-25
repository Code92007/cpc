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
const int N=3e3+100;
int t,n,m,u,v,par[N],dep[N],col[N],fa[N];
P edge[N];
vector<P>e[N];
bool used[N],vis[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
void mer(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return;
    par[v]=u;
}
void dfs(int u){
    vis[u]=1;
    for(auto &x:e[u]){
        int v=x.fi,id=x.se;
        if(vis[v])continue;
        dep[v]=dep[u]+1;
        fa[v]=u;
        col[v]=id;
        used[id]=1;
        dfs(v);
    }
}
bool sol(){
    vector<int>z;
    rep(i,1,m){
        if(used[i])continue;
        z.pb(i);
    }
    int y=SZ(z);
    if(y<3)return 0;
    vector<vector<int>>cyc(y);
    rep(i,0,y-1){
        int id=z[i],u=edge[id].fi,v=edge[id].se;
        if(dep[u]<dep[v])swap(u,v);
        while(dep[u]>dep[v]){
            cyc[i].pb(col[u]);
            u=fa[u];
        }
        while(u!=v){
            cyc[i].pb(col[u]);
            u=fa[u];
            cyc[i].pb(col[v]);
            v=fa[v];
        }
        cyc[i].pb(id);
    }
    int up=(1<<y)-1;
    rep(j,1,up){
        vector<int>cnt(m+1,0);
        rep(k,0,y-1){
            if(!(j>>k&1))continue;
            for(auto &w:cyc[k]){
                cnt[w]++;
            }
        }
        rep(k,1,n)par[k]=k;
        rep(i,1,m){
            if(cnt[i]&1)continue;
            int u=edge[i].fi,v=edge[i].se;
            mer(u,v);
        }
        int anc=find(1);
        bool ok=1;
        rep(i,1,n){
            if(find(i)!=anc){
                ok=0;
                break;
            }
        }
        if(ok)return 1;
    }
    return 0;
}
int main(){
    sci(t);
    while(t--){
        dep[1]=fa[1]=0;
        sci(n),sci(m);
        rep(i,1,n){
            vis[i]=0;
            e[i].clear();
        }
        rep(i,1,m){
            sci(u),sci(v);
            edge[i]=P(u,v);
            used[i]=0;
            e[u].pb(P(v,i));
            e[v].pb(P(u,i));
        }
        dfs(1);
        printf("%s\n",sol()?"YES":"NO");
    }
    return 0;
}