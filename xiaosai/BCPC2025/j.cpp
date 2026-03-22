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
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" "
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
const int N=1e5+10,M=2e5+10;
int n,Q,k,belong[M],block;
bool in[N];
struct Query {
    int l, r, ID, lca, k, ans;
    bool operator < (const Query &rhs) const{
        return belong[l] == belong[rhs.l] ? r < rhs.r : belong[l] < belong[rhs.l];
    //    return belong[l] < belong[rhs.l];
    }
}q[N];
vector<P>e[N];
int a[N],all;
int deep[N], top[N], fa[N], siz[N], son[N], st[N], ed[N], pot[M], tot;
int cnt[N],res[N];
void dfs1(int u,int f,int w) {
    a[u]=w;
    fa[u]=f;
    siz[u]=1;
    st[u]=++tot;
    pot[tot]=u;
    for(auto &x:e[u]){
        int v=x.fi,val=x.se;
        if(deep[v])continue;
        deep[v]=deep[u]+1;
        dfs1(v,u,val);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]){
            son[u]=v;
        }
    }
    ed[u]=++tot;
    pot[tot]=u;
}
void dfs2(int u,int topfa) {
    top[u]=topfa;
    if(!son[u])return;
    dfs2(son[u],topfa);
    for(auto &x:e[u]){
        int v=x.fi;
        if(top[v])continue;
        dfs2(v,v);
    }
}
int GetLca(int x, int y) {
    while(top[x] != top[y]) {
        if(deep[top[x]] < deep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
}
int out[N], used[N], happen[N];
void add(int x) {
    cnt[happen[x]]--;
    happen[x]++;
    res[happen[x]]++;
}
void delet(int x) {
    cnt[happen[x]]--;
    res[happen[x]]--;
    happen[x]--;
}
void Add(int x) {
    //printf("x:%d used:%1d\n",x,used[x]);
    used[x] ? delet(a[x]) : add(a[x]);
    used[x] ^= 1;
}
void Mo() {
    sort(q+1,q+Q+1);
    int l=1,r=0;
    rep(i,1,Q){
        if(q[i].l>q[i].r){
            q[i].ans=0;
            continue;
        }
        while(l < q[i].l) Add(pot[l]), l++;
        while(l > q[i].l) l--, Add(pot[l]);
        while(r < q[i].r) r++, Add(pot[r]);
        while(r > q[i].r) Add(pot[r]), r--;
        //if(q[i].lca) Add(q[i].lca);
        q[i].ans = res[q[i].k];
        //if(q[i].lca) Add(q[i].lca);
    }
    rep(i,1,Q)out[q[i].ID]=q[i].ans;
    rep(i,1,Q)printf("%d\n", out[i]);
}
int main() {
    n=read();
    block=632;
    cnt[0]=n;
    rep(i,1,2*n){
        belong[i]=i/block+1;
    }
    rep(i,2,n){
        int x,y,c;
        x=read();y=read();c=read();
        //scanf("%d%d%d",&x,&y,&c);
        e[x].push_back(P(y,c));
        e[y].push_back(P(x,c));
    }
    deep[1]=1; 
    dfs1(1,0,0);
    dfs2(1,1);
    Q=read();
    // rep(i,1,2*n){
    //     printf("%d ",pot[i]);
    // }
    // puts("");
    rep(i,1,Q){
        int x,y,k;
        x=read();y=read();k=read();
        //scanf("%d%d%d",&x,&y,&k);
        if(st[x]>st[y])swap(x,y);
        int _lca=GetLca(x,y);
        q[i].ID=i;
        if(_lca==x)q[i].l=st[x]+1,q[i].r=st[y],q[i].k=k;
        else q[i].l=ed[x],q[i].r=st[y],q[i].k=k;
        //printf("l:%d r:%d k:%d\n",q[i].l,q[i].r,q[i].k);
    }
    Mo();
    return 0;
}