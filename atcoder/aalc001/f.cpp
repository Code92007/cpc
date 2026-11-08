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
const int N=2e5+10,mod=998244353;
int n,q,op,x,y,a[N],col[N];
char s[N];
struct segtree2{
	int n;
	struct node{
		int l,r,lw,rw;
		ll v,c,lv,rv;
		node(){v=lv=rv=c=0;lw=-1;rw=-2;}
		int sz(){
			return r-l+1;
		}
	}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	#define c(p) e[p].c
	node merge(node l,node r){
		node ans;
		ans.l=l.l,ans.r=r.r;
		ans.v=max(l.v,r.v);
		bool same=l.rw==r.lw;
		if(l.sz()==l.lv && same)ans.lv=l.lv+r.lv;
		else ans.lv=l.lv;
		if(r.sz()==r.rv && same)ans.rv=r.rv+l.rv;
		else ans.rv=r.rv;
		if(same)ans.v=max(ans.v,l.rv+r.lv);
		ans.lw=l.lw,ans.rw=r.rw;
		return ans;
	}
	void up(int p){
		e[p]=merge(e[p<<1],e[p<<1|1]);
	}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){
			e[p].lw=e[p].rw=a[l];
			e[p].v=e[p].lv=e[p].rv=1;
			return;
		}
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
		if(l(p)==r(p)){
			e[p].lw=e[p].rw=v;
			return;
		}
		int mid=l(p)+r(p)>>1;
		chg(p<<1|(x>mid),x,v);
		up(p);
	}
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
    sci(n),sci(q);
    rep(i,1,n)sci(a[i]);
    seg.init(n);
    while(q--){
        sci(op),sci(x),sci(y);
        if(op==1)seg.chg(1,x,y);
        else if(op==2){
			int w=seg.ask(1,x,y).v;
			pte(w);
		}
    }
    return 0;
}