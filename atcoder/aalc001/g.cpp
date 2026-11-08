//#include<bits/stdc++.h>
#include<iostream>
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
const int N=2e5+10,K=5,mod=998244353;
int n,q,op,x,y,z,a[N],c[K][K];
void Add(ll &x,ll y){
	x+=y;
	if(x>=mod)x-=mod;
}
struct segtree2{
	int n;
	struct node{
		int l,r;
		ll v[K],c;
		node(){memset(v,0,sizeof v);c=0;}
	}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define c(p) e[p].c
	node merge(node l,node r){
		node ans;
		ans.l=l.l,ans.r=r.r;
		for(int i=0;i<K;++i){
			ans.v[i]=(l.v[i]+r.v[i])%mod;
		}
		return ans;
	}
	void up(int p){
		e[p]=merge(e[p<<1],e[p<<1|1]);
	}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){
			e[p].v[0]=1;
			ll v=a[l];
			for(int i=1;i<K;++i){
				e[p].v[i]=(1ll*e[p].v[i-1]*v)%mod;
			}
			return;
		}
		int mid=l+r>>1;
		bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
		up(p);
	}
	void op(int p,vector<ll>&w){
		Add(c(p),w[1]);
		for(int i=K-1;i>=1;--i){
			for(int j=0;j<i;++j){
				Add(e[p].v[i],1ll*c[i][j]*e[p].v[j]%mod*w[i-j]%mod);
			}
		}
	}
	void psd(int p){
		if(c(p)){
			ll v=c(p);
			vector<ll>w(K,1);
			for(int i=1;i<K;++i){
				w[i]=1ll*w[i-1]*v%mod;
			}
			op(p<<1,w);
			op(p<<1|1,w);
			c(p)=0; 
		}
	}
	void init(int _n){n=_n;bld(1,1,n);}
	void add(int p,int ql,int qr,vector<ll>&w){
		if(ql<=l(p)&&r(p)<=qr){
			op(p,w);
			return;
		}
		psd(p);
		int mid=l(p)+r(p)>>1;
		if(ql<=mid)add(p<<1,ql,qr,w);
		if(qr>mid)add(p<<1|1,ql,qr,w);
		up(p);
	}
	node ask(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return e[p];
		int mid=l(p)+r(p)>>1;
		node res;
		psd(p);
		if(ql<=mid && qr>mid){
			res=merge(ask(p<<1,ql,qr),ask(p<<1|1,ql,qr));
		}
		else if(ql<=mid){
			res=ask(p<<1,ql,qr);
		}
		else if(qr>mid){
			res=ask(p<<1|1,ql,qr);
		}
		return res;
	}
}seg;
int main(){
	c[0][0]=1;
	for(int i=1;i<K;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
    sci(n),sci(q);
    rep(i,1,n)sci(a[i]);
    seg.init(n);
    while(q--){
        sci(op),sci(x),sci(y),sci(z);
        if(op==1){
			if(!z)continue;
			vector<ll>w(K,1);
			for(int i=1;i<K;++i){
				w[i]=1ll*w[i-1]*z%mod;
			}
			seg.add(1,x,y,w);
		}
        else if(op==2){
			ll w=seg.ask(1,x,y).v[z];
			w=(w%mod+mod)%mod;
			ptlle(w);
		}
    }
    return 0;
}