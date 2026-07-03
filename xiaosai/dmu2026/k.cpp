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
const int N=2e5+10,M=19;
int t,n,q,u,v,in[N],out[N],tot,par[N];
int f[N][M],dep[N];
bool vis[N];
vector<int>e[N];
struct segtree1{
	int n;
	struct node{int l,r,v;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	void up(int p){v(p)=v(p<<1)+v(p<<1|1);}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){v(p)=0;return;}
		int mid=l+r>>1;
		bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
		up(p);
	}
	void init(int _n){n=_n;bld(1,1,n);}
	void chg(int p,int x,int v){
		if(l(p)==r(p)){v(p)+=v;return;}
		int mid=l(p)+r(p)>>1;
		chg(p<<1|(x>mid),x,v);
		up(p);
	}
	int cnt(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return v(p);
		int mid=l(p)+r(p)>>1,res=0;
		if(ql<=mid)res+=cnt(p<<1,ql,qr);
		if(qr>mid)res+=cnt(p<<1|1,ql,qr);
		return res;
	}
}seg;
void dfs(int u,int fa){
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<18;++i){
		f[u][i]=f[f[u][i-1]][i-1];
	}
    in[u]=++tot;
    par[u]=fa;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
    out[u]=tot;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=17;i>=0;--i)
	if(d>>i&1)x=f[x][i];
	if(x==y)return x;
	for(int i=17;i>=0;--i){
		if(f[x][i]!=f[y][i])
		x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int dis(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(q);
        rep(i,1,n){
            in[i]=out[i]=0;
            e[i].clear();
            vis[i]=0;
        }
        tot=0;
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(1,0);
        seg.init(tot);
        int las=1;
        ll sum=0,mx=0;
        int pos=1;
        while(q--){
            int op,x;
            sci(op),sci(x);
            if(op==1){
                vis[x]^=1;
                int w=dis(x,pos);
                //printf("x:%d visx:%1d pos:%d w:%d\n",x,vis[x],pos,w);
                if(vis[x])sum+=w,seg.chg(1,in[x],1);
                else sum-=w,seg.chg(1,in[x],-1);
            }
            else{
                if(par[x]==pos){
                    ll w=seg.cnt(1,1,tot);
                    ll y=seg.cnt(1,in[x],out[x]);
                    sum-=y;
                    sum+=w-y;
                }
                else{
                    ll w=seg.cnt(1,1,tot);
                    ll y=seg.cnt(1,in[pos],out[pos]);
                    sum+=y;
                    sum-=w-y;
                }
                pos=x;
            }
            //printf("sum:%lld\n",sum);
            if(sum>mx)mx=sum,las=pos;
            else if(sum==mx)las=min(las,pos);
        }
        printf("%d\n",las);
    }
    return 0;
}