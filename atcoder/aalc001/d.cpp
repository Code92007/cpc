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
struct segtree2{
	int n;
	struct node{
		int l,r;ll v,c,a[3];
		node(){memset(a,0,sizeof a);v=c=0;}
	}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	#define c(p) e[p].c
	node merge(node l,node r){
		node ans;
		ans.l=l.l,ans.r=r.r;
		for(int i=0;i<3;++i){
			ans.a[i]=l.a[i]+r.a[i];
		}
		ans.v=l.v+r.v;
		for(int i=0;i<3;++i){
			for(int j=0;j<i;++j){
				ans.v+=1ll*l.a[i]*r.a[j];
			}
		}
		return ans;
	}
	void up(int p){
		e[p]=merge(e[p<<1],e[p<<1|1]);
	}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){v(p)=0;c(p)=0;e[p].a[a[l]]=1;return;}
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
		if(l(p)==r(p)){memset(e[p].a,0,sizeof e[p].a);e[p].a[v]=1;return;}
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
		if(ql<=mid)res=merge(res,ask(p<<1,ql,qr));
		if(qr>mid)res=merge(res,ask(p<<1|1,ql,qr));
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
			ptlle(seg.ask(1,x,y).v);
		}
    }
    return 0;
}