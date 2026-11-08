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
int n,q,op,x,y,a[N];
ll z;
struct segtree2{
	int n;
	struct node{
		int l,r,rp0;
		ll v,c;
		node(){v=c=0;rp0=-1;}
	}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define c(p) e[p].c
	node merge(node l,node r){
		node ans;
		ans.l=l.l,ans.r=r.r;
		ans.v=l.v+r.v;
		ans.rp0=max(l.rp0,r.rp0);
		return ans;
	}
	void up(int p){
		e[p]=merge(e[p<<1],e[p<<1|1]);
	}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){
			e[p].v=a[l];
			if(a[l]==0)e[p].rp0=l;
			else e[p].rp0=-1;
			return;
		}
		int mid=l+r>>1;
		bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
		up(p);
	}
	void init(int _n){n=_n;bld(1,1,n);}
	void chg(int p,int x,int v){
		if(l(p)==r(p)){
			e[p].v=v;
			if(v==0)e[p].rp0=l(p);
			else e[p].rp0=-1;
			return;
		}
		int mid=l(p)+r(p)>>1;
		chg(p<<1|(x>mid),x,v);
		up(p);
	}
	node ask(int p,int ql,int qr){
		node res;
		if(ql>qr)return res;
		if(ql<=l(p)&&r(p)<=qr)return e[p];
		int mid=l(p)+r(p)>>1;
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
	//区间[l,r]中0的最右位置，线段树二分
	int askr(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr){
			return e[p].rp0;
		}
		if(e[p].rp0==-1)return -1;
		int mid=l(p)+r(p)>>1;
		if(qr>mid){
			int ans=askr(p<<1|1,ql,qr);
			if(~ans)return ans;
		}
		if(ql<=mid){
			int ans=askr(p<<1,ql,qr);
			if(~ans)return ans;
		}
		return -1;
	}
}seg;
int main(){
    sci(n),sci(q);
    rep(i,1,n)sci(a[i]);
    seg.init(n);
    while(q--){
        sci(op),sci(x),sci(y);
        if(op==1){
			seg.chg(1,x,y);
		}
        else if(op==2){
			scanf("%lld",&z);
			int rp0=seg.askr(1,x,y);
			if(rp0==-1)ptlle(z+seg.ask(1,x,y).v);
			else{
				//printf("x:%d rp0:%d w:%lld\n",x,rp0,seg.ask(1,x,rp0).v);
				ll lsum=(z+seg.ask(1,x,rp0).v)%mod;
				ll rsum=seg.ask(1,rp0+1,y).v;
				//printf("ls:%lld rs:%lld\n",lsum,rsum);
				ptlle(lsum+rsum);
			}
		}
    }
    return 0;
}