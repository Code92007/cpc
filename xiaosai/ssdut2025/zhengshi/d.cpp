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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=5e5+10;
int n,m,k,a[N],x,y,z;
ll b[N],c[N],all;
struct segtree{
	int n;
	struct node{int l,r;ll v,c;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	#define c(p) e[p].c
	void up(int p){v(p)=max(v(p<<1),v(p<<1|1));}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;c(p)=0;
		if(l==r){v(p)=c[l];return;}
		int mid=l+r>>1;
		bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
		up(p);
	}
	void psd(int p){
		if(c(p)){
			v(p<<1)+=c(p);
			c(p<<1)+=c(p);
			v(p<<1|1)+=c(p);		
			c(p<<1|1)+=c(p);
			c(p)=0; 
		}
	}
	void init(int _n){n=_n;bld(1,1,n);}
	void chg(int p,int x,int v){
		if(l(p)==r(p)){v(p)=v;return;}
		int mid=l(p)+r(p)>>1;
		psd(p);
		chg(p<<1|(x>mid),x,v);
		up(p);
	}
	void add(int p,int ql,int qr,ll v){
		if(ql<=l(p)&&r(p)<=qr){
			v(p)+=v;
			c(p)+=v;
			return;
		}
		psd(p);
		int mid=l(p)+r(p)>>1;
		if(ql<=mid)add(p<<1,ql,qr,v);
		if(qr>mid)add(p<<1|1,ql,qr,v);
		up(p);
	}
	ll cnt(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return v(p);
		int mid=l(p)+r(p)>>1;ll res=0;
		psd(p);
		if(ql<=mid)res=max(res,cnt(p<<1,ql,qr));
		if(qr>mid)res=max(res,cnt(p<<1|1,ql,qr));
		return res;
	}
}seg;
void cal(){
    printf("%lld\n",all-seg.cnt(1,1,z));
}
int main(){
    sci(n),sci(m),sci(k);
    rep(i,1,n){
        sci(a[i]);
        b[i]=b[i-1]+a[i];
        if(i>=k)c[i-k+1]=b[i]-b[i-k];
        all+=a[i];
    }
    z=n-k+1;
    seg.init(z);
    cal();
    while(m--){
        sci(x),sci(y);
        int l=max(x-k+1,1);
        ll delta=y-a[x];
        all+=delta;
        seg.add(1,l,x,delta);
        a[x]=y;
        cal();
    }
    return 0;
}