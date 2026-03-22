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
typedef pair<int,int> P;
typedef array<int,3> A;
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
const int N=1e6+10,M=20;
int st[N][M],dep[N];
int t,n,a[N],b[N],cnt[N],now[N],par[N],add[N];
bool vis[N],used[N];
vector<int>ans;
vector<P>e[N];
map<int,bool>lef,rig;
vector<int>l,r;
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
void merge(int x,int y,int i){
    int u=find(x),v=find(y);
    if(u==v)return;
    par[v]=u;
    e[x].pb(P(y,i));
    e[y].pb(P(x,i));
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=19;~i;i--){
        if(dep[st[u][i]]>=dep[v])u=st[u][i];
    }
    if(u==v)return u;
    for(int i=19;~i;i--){
        if(st[u][i]==st[v][i])continue;
        u=st[u][i];
        v=st[v][i];
    }
    return st[u][0];
}
void dfs(int u,int fa){
    vis[u]=1;
    if(now[u]<cnt[u])l.pb(u);
    else if(now[u]>cnt[u])r.pb(u);
    dep[u]=dep[fa]+1;
    st[u][0]=fa;
    for(int i=1;i<20;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(auto &x:e[u]){
        int v=x.fi;
        if(v==fa || vis[v])continue;
        dfs(v,u);
    }
}
void dfs2(int u,int fa){
    for(auto &x:e[u]){
        int v=x.fi;
        if(v==fa)continue;
        dfs2(v,u);
        add[u]+=add[v];
        if(add[v]%2==1){
            ans.pb(x.se);
        }
    }
}
// void out(){
//     rep(i,1,n){
//         printf("%d ",a[i]);
//     }
//     puts("");
//     rep(i,1,n){
//         printf("%d ",b[i]);
//     }
//     puts("");
// }
bool sol(){
    rep(i,1,n){
        if(cnt[i]%2==1)return 0;
        cnt[i]/=2;
    }
    rep(i,1,n){
        now[a[i]]++;
    }
    lef.clear();
    rig.clear();
    rep(i,1,n){
        if(a[i]==b[i]){
            used[i]=1;
            continue;
        }
        if(now[a[i]]>cnt[i] && now[b[i]]<cnt[i]){
            used[i]=1;
            now[a[i]]--;
            now[b[i]]++;
            ans.pb(i);
        }
    }
    rep(i,1,n){
        if(used[i])continue;
        merge(a[i],b[i],i);
        if(now[i]<cnt[i])lef[i]=true;
        else if(now[i]>cnt[i])rig[i]=true;
    }
    rep(i,1,n){
        if(!vis[i]){
            l.clear();
            r.clear();
            dfs(i,0);
            if(SZ(l)!=SZ(r))return 0;
            int sz=SZ(l);
            rep(j,0,sz-1){
                int x=l[j],y=r[j];
                //printf("x:%d y:%d lca:%d\n",x,y,lca(x,y));
                add[x]++;add[y]++;
                add[lca(x,y)]-=2;
            }
            dfs2(i,0);
        }
    }
    pte(SZ(ans));
    for(auto &v:ans){
        printf("%d ",v);
    }
    puts("");
    ans.clear();
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            par[i]=i;
            used[i]=0;
            add[i]=0;
            vis[i]=0;
            e[i].clear();
            cnt[i]=0;
            now[i]=0;
        }
        rep(i,1,n){
            sci(a[i]);
            cnt[a[i]]++;
        }
        rep(i,1,n){
            sci(b[i]);
            cnt[b[i]]++;
        }
        if(!sol()){
            puts("-1");
        }
    }
    return 0;
}