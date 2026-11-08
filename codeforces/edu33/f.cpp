#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=20*N,INF=0x3f3f3f3f;
int n,m,rt,u,v,mxd,a[N];
int sz[N],dep[N],dfn[N],tot;
int root[N],ls[M],rs[M],mn[M],c;
vector<int>e[N],d[N];
void upd(int l,int r,int &cur,int las,int pos,int v){
	cur=++c;
    ls[cur]=ls[las];
    rs[cur]=rs[las];
    mn[cur]=min(mn[las],v);
	if(l==r)return;
	int mid=(l+r)/2;
	if(pos<=mid)upd(l,mid,ls[cur],ls[las],pos,v);
	else upd(mid+1,r,rs[cur],rs[las],pos,v);
}
int ask(int cur,int l,int r,int ql,int qr){
    if(!cur)return INF;
    if(ql<=l && r<=qr)return mn[cur];
    int mid=(l+r)/2,ans=INF;
    if(ql<=mid)ans=min(ans,ask(ls[cur],l,mid,ql,qr));
    if(qr>mid)ans=min(ans,ask(rs[cur],mid+1,r,ql,qr));
    return ans;
}
void dfs(int u,int fa){
    d[dep[u]].push_back(u);
    mxd=max(mxd,dep[u]);
    dfn[u]=++tot;
    sz[u]=1;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
void init(){
    memset(mn,INF,sizeof mn);
    for(int i=1;i<=mxd;++i){
        int old=root[i-1];
        for(auto &v:d[i]){
            upd(1,n,root[i],old,dfn[v],a[v]);
            old=root[i];
        }
    }
}
int main(){
    scanf("%d%d",&n,&rt);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dep[rt]=1;
    dfs(rt,0);
    init();
    int las=0;
    scanf("%d",&m);
    while(m--){
        int p,q;
        scanf("%d%d",&p,&q);
        u=((p+las)%n)+1;
        v=(q+las)%n;
        int l=dfn[u],r=dfn[u]+sz[u]-1;
        printf("%d\n",las=ask(root[min(mxd,dep[u]+v)],1,n,l,r));
    }
    return 0;
}