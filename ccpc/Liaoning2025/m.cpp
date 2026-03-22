//#include <bits/stdc++.h>
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
const int N=2e6+10,M=2e6+10,INF=1e9;
const ll UP=1e18;
int n,c;
ll x[M];
P a[N];
bool cmp(P x,P y){
	if(max(x.fi,x.se)==max(y.fi,y.se)){
		if(x.fi<x.se && y.fi>y.se)return 1;
	}
	return max(x.fi,x.se)<max(y.fi,y.se);
}
struct segtree{
	int n;
	struct node{int l,r,v,c;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
    #define c(p) e[p].c
	void up(int p){v(p)=max(v(p<<1),v(p<<1|1));}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){v(p)=0;return;}
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
		if(l(p)==r(p)){v(p)=max(v(p),v);return;}
		int mid=l(p)+r(p)>>1;
		psd(p);
		chg(p<<1|(x>mid),x,v);
		up(p);
	}
	void add(int p,int ql,int qr,int v){
        if(ql>qr)return;
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
	int cnt(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return v(p);
		int mid=l(p)+r(p)>>1,res=0;
		psd(p);
		if(ql<=mid)res=max(res,cnt(p<<1,ql,qr));
		if(qr>mid)res=max(res,cnt(p<<1|1,ql,qr));
		return res;
    }
}seg;
int main(){
    sci(n);
	assert(n<=1000000);
    x[c++]=0;
    rep(i,1,n){
        scanf("%lld%lld",&a[i].fi,&a[i].se);
		assert(0<=a[i].fi && a[i].fi<=UP);
		assert(0<=a[i].se && a[i].se<=UP);
        x[c++]=a[i].fi;
        x[c++]=a[i].se;
    }
    sort(a+1,a+n+1,cmp);
    sort(x,x+c);
    c=unique(x,x+c)-x;
    seg.bld(1,1,c);
    //rep(i,1,c)printf("i:%d c:%d\n",i,x[i-1]);
    rep(i,1,n){
        int from=lower_bound(x,x+c,a[i].fi)-x+1,to=lower_bound(x,x+c,a[i].se)-x+1;
        //printf("i:%d from:%d to:%d (%lld,%lld)\n",i,from,to,a[i].fi,a[i].se);
        if(from<=to){
            int w=seg.cnt(1,1,from)+1;
            //printf("i:%d w:%d to:%d\n",i,w,to);
            seg.chg(1,to,w);
        }
        else{
            int w=seg.cnt(1,1,to)+1;
            //printf("i:%d w:%d [%d,%d]\n",to+1,from);
            seg.chg(1,to,w);
            seg.add(1,to+1,from,1);
        }
    }
    printf("%d\n",seg.cnt(1,1,c));
    return 0;
}