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
int n,q,op,x,a[N];
ll y;
struct segtree2{
	int n;
	struct node{int l,r;ll v,c;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	#define c(p) e[p].c
	void up(int p){v(p)=v(p<<1)+v(p<<1|1);}
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
	void chg(int p,int x,ll v){
		if(l(p)==r(p)){v(p)=v;return;}
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
	ll ask(int p,int ql,int qr){
		if(ql>qr)return 0;
		if(ql<=l(p)&&r(p)<=qr)return v(p);
		int mid=l(p)+r(p)>>1;
		ll res=0;
		psd(p);
		if(ql<=mid)res+=ask(p<<1,ql,qr);
		if(qr>mid)res+=ask(p<<1|1,ql,qr);
		return res;
	}
	int askr(int p,ll v){
		if(l(p)==r(p))return l(p);
		if(v(p)<v)return -1;
		int mid=l(p)+r(p)>>1;
		ll res=0;
		psd(p);
		if(v(p<<1)>=v)return askr(p<<1,v);
		return askr(p<<1|1,v-v(p<<1));
	}
	int askl(int p,ll v){
		if(l(p)==r(p))return l(p);
		if(v(p)<v)return -1;
		int mid=l(p)+r(p)>>1;
		ll res=0;
		psd(p);
		if(v(p<<1|1)>=v)return askl(p<<1|1,v);
		return askl(p<<1,v-v(p<<1|1));
	}
}seg;
int main(){
    sci(n),sci(q);
    rep(i,1,n)sci(a[i]);
    seg.init(n);
    while(q--){
        sci(op),sci(x);
		scanf("%lld",&y);
        if(op==1)seg.chg(1,x,y);
        else if(op==2){
			ll mx=seg.ask(1,x,n);
			if(mx<y)pte(n+1);
			else{
				y+=seg.ask(1,1,x-1);
				pte(seg.askr(1,y));
			}
		}
		else{
			ll mx=seg.ask(1,1,x);
			if(mx<y)pte(0);
			else{
				y+=seg.ask(1,x+1,n);
				pte(seg.askl(1,y));
			}
		}
    }
    return 0;
}