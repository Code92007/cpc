//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
using namespace std;
const int N=2e5+10;
const ll INF=1e18;
int n,a[N],mx,mn;
int c,stk[N];
int c2,stk2[N];
ll dp[N];
struct segtree{
	int n;
	struct node{int l,r;ll v,c;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	#define c(p) e[p].c
	void up(int p){v(p)=min(v(p<<1),v(p<<1|1));}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){v(p)=INF;c(p)=0;return;}
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
		psd(p);
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
	ll cnt(int p,int ql,int qr){
        if(ql>qr)return INF;
		if(ql<=l(p)&&r(p)<=qr)return v(p);
		int mid=l(p)+r(p)>>1;
        ll res=INF;
		psd(p);
		if(ql<=mid)res=min(res,cnt(p<<1,ql,qr));
		if(qr>mid)res=min(res,cnt(p<<1|1,ql,qr));
		return res;
	}
}seg;
int main(){
    sci(n);
    seg.init(n);
    rep(i,1,n){
        sci(a[i]);
        while(c && a[stk[c]]<=a[i]){
            int pre=stk[c--],ppre=!c?1:stk[c]+1;
            seg.add(1,ppre,pre,a[i]-a[pre]);
        }
        while(c2 && a[stk2[c2]]>=a[i]){
            int pre=stk2[c2--],ppre=!c2?1:stk2[c2]+1;
            seg.add(1,ppre,pre,a[pre]-a[i]);
        }
        stk[++c]=i;
        stk2[++c2]=i;
        seg.chg(1,i,dp[i-1]);
        if(i>=2)dp[i]=seg.cnt(1,1,i-1);
        else dp[i]=INF;
        //printf("i:%d dp:%lld\n",i,dp[i]);
    }
    ptlle(dp[n]);
    return 0;
}