//#include<bits/stdc++.h>
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
const int N=3e5+10;
int t,n,a[N];
struct segtree{
	int n;
	struct node{
        int l,r;
        ll c,v,mx;
    }e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	#define c(p) e[p].c
	#define mx(p) e[p].mx
	void up(int p){
        v(p)=v(p<<1)+v(p<<1|1);
        mx(p)=max(mx(p<<1),mx(p<<1|1));
    }
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;c(p)=-1;
		if(l==r){v(p)=0;return;}
		int mid=l+r>>1;
		bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
		up(p);
	}
	void psd(int p){
		if(~c(p)){
			v(p<<1)=1ll*(r(p<<1)-l(p<<1)+1)*c(p);
            mx(p<<1)=c(p);
			c(p<<1)=c(p);
			v(p<<1|1)=1ll*(r(p<<1|1)-l(p<<1|1)+1)*c(p);		
			c(p<<1|1)=c(p);
            mx(p<<1|1)=c(p);
			c(p)=-1;
		}
	}
	void init(int _n){n=_n;bld(1,1,n);}
	void upd(int p,int ql,int qr,int v){
		if(ql<=l(p)&&r(p)<=qr){
			v(p)=1ll*(r(p)-l(p)+1)*v;
            mx(p)=v;
			c(p)=v;
			return;
		}
		psd(p);
		int mid=l(p)+r(p)>>1;
		if(ql<=mid)upd(p<<1,ql,qr,v);
		if(qr>mid)upd(p<<1|1,ql,qr,v);
		up(p);
	}
	P cnt(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return P(v(p),mx(p));
		int mid=l(p)+r(p)>>1;
        ll res=0,w=0;
		psd(p);
		if(ql<=mid){
            auto L=cnt(p<<1,ql,qr);
            res+=L.fi;
            w=max(w,L.se);
        }
		if(qr>mid){
            auto R=cnt(p<<1|1,ql,qr);
            res+=R.fi;
            w=max(w,R.se);
        }
		return P(res,w);
	}
}dp[2];
int main(){
    sci(n);
    dp[0].init(n);
    dp[1].init(n);
    rep(i,1,n){
        sci(a[i]);
        dp[0]
    }
    return 0;
}