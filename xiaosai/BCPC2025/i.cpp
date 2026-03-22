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
#define pb push_back
#define fi first
#define se second
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
typedef pair<int,int> P;
typedef array<int,5> A;
const int N=1e5+10;
P edge[N];
vector<P>dat[4*N];
int n,m,q,k,v,par[N],sz[N],cnt[N],deg[N],now;
int ans[N];
vector<int>del[N];
int find(int x){
	return par[x]==x?x:find(par[x]);
}
void merge(int u,int v,stack<A> &q){
	int x=find(u),y=find(v);
    deg[u]++;
    deg[v]++;
	if(x==y){
        now-=max(1,cnt[x]/2);
        if(deg[u]%2==0)cnt[x]--;
        else cnt[x]++;
        if(deg[v]%2==0)cnt[x]--;
        else cnt[x]++;
        now+=max(1,cnt[x]/2);
        q.push({u,v,x,y,0});
        //printf("after merge1 u:%d v:%d, now:%d\n",u,v,now);
        return;
    }
	if(sz[x]<sz[y])swap(x,y),swap(u,v);
    //printf("before cntx:%d cnty:%d degu:%d degv:%d\n",cnt[x],cnt[y],deg[u],deg[v]);
    //printf("now1:%d\n",now);
    now-=max(1,cnt[x]/2);
    now-=max(1,cnt[y]/2);
    //printf("now2:%d\n",now);
    if(deg[u]%2==0)cnt[x]--;
    else cnt[x]++;
    if(deg[v]%2==0)cnt[y]--;
    else cnt[y]++;
    q.push({u,v,x,y,1});
	sz[x]+=sz[y]; 
    cnt[x]+=cnt[y];
	par[y]=x;
    now+=max(1,cnt[x]/2);
    //printf("cntx:%d now3:%d\n",cnt[x],now);
    //printf("after cntx:%d degu:%d degv:%d\n",cnt[x],deg[u],deg[v]);
    //printf("after merge2 u:%d v:%d, now:%d\n",u,v,now);
}
void undo(stack<A> &q){
	while(!q.empty()){
        auto w=q.top();
        q.pop();
        int u=w[0],v=w[1],x=w[2],y=w[3],op=w[4];
        if(op==0){
            now-=max(1,cnt[x]/2);
            if(deg[u]%2==0)cnt[x]++;
            else cnt[x]--;
            if(deg[v]%2==0)cnt[x]++;
            else cnt[x]--;
            now+=max(1,cnt[x]/2);
        }
        else{
            now-=max(1,cnt[x]/2);
            sz[x]-=sz[y];
            cnt[x]-=cnt[y];
            par[y]=y;
            if(deg[u]%2==0)cnt[x]++;
            else cnt[x]--;
            if(deg[v]%2==0)cnt[y]++;
            else cnt[y]--;
            now+=max(1,cnt[x]/2);
            now+=max(1,cnt[y]/2);
        }
        deg[u]--;
        deg[v]--;
	} 
} 
void update(int p,int l,int r,int ql,int qr,P v){
	if(ql<=l&&r<=qr){
		dat[p].pb(v);
		return;
	}
	int mid=(l+r)/2;
	if(ql<=mid)update(lson,ql,qr,v);
	if(qr>mid)update(rson,ql,qr,v);
}
void dfs(int p,int l,int r){
	stack<A>q;
	for(auto v:dat[p])
	merge(v.fi,v.se,q); 
    //printf("in p:%d l:%d r:%d now:%d\n",p,l,r,now);
	if(l==r)ans[l]=now;
	else{
		int mid=(l+r)/2;
		dfs(lson);
		dfs(rson);
	}
	undo(q);
    //printf("out p:%d l:%d r:%d now:%d\n",p,l,r,now);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i){
        scanf("%d%d",&edge[i].fi,&edge[i].se);
    }
    for(int i=1;i<=q;++i){
        scanf("%d",&k);
        for(int j=1;j<=k;++j){
            scanf("%d",&v);
            del[v].push_back(i);
        }
    }
    for(int i=1;i<=m;++i){
        int las=0;
        if(!del[i].empty()){
            for(auto &w:del[i]){
                if(las+1<=w-1){
                    //printf("l:%d r:%d i:%d\n",las+1,w-1,i);
                    update(1,1,q,las+1,w-1,edge[i]);
                }
                las=w;
            }
        }
        if(las+1<=q){
            //printf("l:%d r:%d i:%d\n",las+1,q,i);
            update(1,1,q,las+1,q,edge[i]);
        }
    }
	for(int i=1;i<=n;++i){
	    par[i]=i;
        deg[i]=0;
        sz[i]=1;
        cnt[i]=0;
    }
    now=n;
	dfs(1,1,q);
	for(int i=1;i<=q;++i){
	    printf("%d\n",ans[i]);
    }
	return 0;
}