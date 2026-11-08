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
int n,q,op,x,y,a[N];
struct segtree1{
	int n;
	struct node{int l,r,v;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	void up(int p){v(p)=min(v(p<<1),v(p<<1|1));}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){v(p)=a[l];return;}
		int mid=l+r>>1;
		bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
		up(p);
	}
	void init(int _n){n=_n;bld(1,1,n);}
	void chg(int p,int x,int v){
		if(l(p)==r(p)){v(p)=v;return;}
		int mid=l(p)+r(p)>>1;
		chg(p<<1|(x>mid),x,v);
		up(p);
	}
	int ask(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return v(p);
		int mid=l(p)+r(p)>>1,res=1e9;
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
        if(op==1)seg.chg(1,x,y);
        else pte(seg.ask(1,x,y));
    }
    return 0;
}