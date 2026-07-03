//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<random>
#include<algorithm>
#include<cmath>
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
const int N=1e6+10,K=21,INF=1e9+7;
int n,m,q,a[N],cost[N],par[N],st[N][K],tot;
int dfn[N],cnt,dep[N],id[N];
int op[N],x[N],y[N];
ll z[N],c,lg[N],b[N];
vector<int>f[N];
struct Bit{
	int n,tr[N];
	void init(int _n){
		n=_n;
		memset(tr,0,(n+1)*sizeof(*tr));
	}
	void add(int x,int v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]+=v;
	}
	int sum(int x){
		int ans=0; 
		for(int i=x;i;i-=i&-i)
		ans+=tr[i];
		return ans;
	}
    // 树状数组求从小到大第k个, 1<=k<=sum(n), 1<=x<=n
    int kth(int k){
        int x=0;
        for(int i=1<<lg[n];i;i>>=1){
            if(x+i<=n && k>tr[x+i]){
                x+=i;
                k-=tr[x];
            }
        }
        return x+1;
    }
}tr;
struct segtree{
	int n;
	struct node{int l,r,mn,mx;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define mn(p) e[p].mn
    #define mx(p) e[p].mx
	void up(int p){
        mn(p)=min(mn(p<<1),mn(p<<1|1));
        mx(p)=max(mx(p<<1),mx(p<<1|1));
    }
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){mn(p)=INF;mx(p)=0;return;}
		int mid=l+r>>1;
		bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
		up(p);
	}
	void init(int _n){n=_n;bld(1,1,n);}
	void chg(int p,int x,int v){
		if(l(p)==r(p)){mn(p)=mx(p)=v;return;}
		int mid=l(p)+r(p)>>1;
		chg(p<<1|(x>mid),x,v);
		up(p);
	}
    void del(int p,int x){
		if(l(p)==r(p)){mn(p)=INF;mx(p)=0;return;}
		int mid=l(p)+r(p)>>1;
		del(p<<1|(x>mid),x);
		up(p);
	}
	P ask(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return P(mn(p),mx(p));
		int mid=l(p)+r(p)>>1;
        P res=P(INF,0);
		if(ql<=mid){
            P L=ask(p<<1,ql,qr);
            res.fi=min(res.fi,L.fi);
            res.se=max(res.se,L.se);
        }
		if(qr>mid){
            P R=ask(p<<1|1,ql,qr);
            res.fi=min(res.fi,R.fi);
            res.se=max(res.se,R.se);
        }
		return res;
	}
}seg;
struct edge{
    int u,v,w;
    bool operator<(const edge &x)const{
        return w<x.w;
    }
}e[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
void merge(int x,int y,int w){
    x=find(x),y=find(y);
    if(x==y)return;
    ++tot;
    par[x]=par[y]=st[x][0]=st[y][0]=tot;
    cost[tot]=w;
    f[tot].pb(x);
    f[tot].pb(y);
    //printf("tot:%d totson:%d %d w:%d\n",tot,x,y,w);
}
void Kruskal(){
    rep(i,1,2*n){
        par[i]=i;
    }
    sort(e+1,e+m+1);
    tot=n;
    rep(i,1,m){
        int u=find(e[i].u),v=find(e[i].v),w=e[i].w;
        merge(u,v,w);
        if(tot==2*n-1){
            break;
        }
    }
}
void dfs(int u,int fa){
    dfn[u]=++cnt;
    id[cnt]=u;
    dep[u]=dep[fa]+1;
    for(int i=1;i<20;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(auto &v:f[u]){
        dfs(v,u);
    }
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
ll cal(int x,int y){
    return 1ll*y*INF-x;
}
int main(){
    sci(n),sci(m),sci(q);
    rep(i,1,n){
        sci(a[i]);
        z[c++]=cal(i,a[i]);
    }
    rep(i,1,m){
        sci(e[i].u),sci(e[i].v),sci(e[i].w);
    }
    Kruskal();
    dfs(tot,0);
    rep(i,1,q){
        sci(op[i]);
        sci(x[i]);
        if(op[i]==1){
            sci(y[i]);
            z[c++]=cal(x[i],y[i]);
        }
    }
    sort(z,z+c);
    c=unique(z,z+c)-z;
    rep(i,2,N-5){
        lg[i]=lg[i>>1]+1;
    }
    tr.init(c);
    seg.init(c);
    rep(i,1,n){
        ll v=cal(i,a[i]);
        b[i]=lower_bound(z,z+c,v)-z+1;
        //printf("i:%d b:%d dfn:%d\n",i,b[i],dfn[i]);
        seg.chg(1,b[i],dfn[i]);
        tr.add(b[i],1);
    }
    //printf("c:%d\n",c);
    rep(i,1,q){
        if(op[i]==1){
            int u=x[i],w=y[i];
            tr.add(b[u],-1);
            seg.del(1,b[u]);
            ll v=cal(u,w);
            //printf("oribi:%d\n",b[u]);
            b[u]=lower_bound(z,z+c,v)-z+1;
            //printf("nowbi:%d dfn:%d\n",b[u],dfn[u]);
            seg.chg(1,b[u],dfn[u]);
            tr.add(b[u],1);
        }
        else{
            int p=tr.kth(n-x[i]+1);
            //printf("p:%d\n",p);
            P x=seg.ask(1,p,c);
            //printf("x.fi:%d x.se:%d\n",x.fi,x.se);
            //printf("x.fi:%d x.se:%d\n",id[x.fi],id[x.se]);
            //printf("lca:%d\n",lca(id[x.fi],id[x.se]));
            printf("%d\n",cost[lca(id[x.fi],id[x.se])]);
        }
    }
    return 0;
}
/*
4 4 8
4 3 2 1
1 2 4
3 2 1
3 4 2
4 1 3
2 2
1 3 4
1 4 4 
2 2
1 3 5
1 4 6
2 2
2 1
*/