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
const int N=2e5+10;
int n,q,op,x,y,z,a[N];
struct segtree2{
	int n;
	struct node{int l,r;ll v,c;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	#define c(p) e[p].c
	void up(int p){v(p)=min(v(p<<1),v(p<<1|1));}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){v(p)=a[l];c(p)=0;return;}
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
	void add(int p,int ql,int qr,int v){
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
	ll ask(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return v(p);
		int mid=l(p)+r(p)>>1;
		ll res=1e18;
		psd(p);
		if(ql<=mid)res=min(res,ask(p<<1,ql,qr));
		if(qr>mid)res=min(res,ask(p<<1|1,ql,qr));
		return res;
	}
}seg;
int main(){
    sci(n),sci(q);
    rep(i,1,n)sci(a[i]);
    seg.init(n);
    while(q--){
        sci(op),sci(x),sci(y);
        if(op==1)sci(z),seg.add(1,x,y,z);
        else ptlle(seg.ask(1,x,y));
    }
    return 0;
}