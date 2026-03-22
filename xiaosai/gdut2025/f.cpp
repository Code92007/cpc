//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
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
const int N=2e5+10;
int t,n,q;
int op[N],x[N],y[N],e[N];
ll val[N];
struct segtree{
	int n;
	struct node{int l,r;ll v;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	void up(int p){v(p)=max(v(p<<1),v(p<<1|1));}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){v(p)=0;return;}
		int mid=l+r>>1;
		bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
		up(p);
	}
	void init(int _n){n=_n;bld(1,0,n);}
	void chg(int p,int x,int v){
		if(l(p)==r(p)){v(p)+=v;return;}
		int mid=l(p)+r(p)>>1;
		chg(p<<1|(x>mid),x,v);
		up(p);
	}
	ll cnt(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return v(p);
		int mid=l(p)+r(p)>>1;
        ll res=0;
		if(ql<=mid)res=max(res,cnt(p<<1,ql,qr));
		if(qr>mid)res=max(res,cnt(p<<1|1,ql,qr));
		return res;
	}
}seg;
int main(){
    sci(t);
    while(t--){
        sci(n),sci(q);
        seg.init(2*n);
        ll ans=0;
        rep(i,1,q){
            sci(op[i]),sci(x[i]),sci(y[i]),sci(e[i]);
            //ans=max(ans,e[i]);
            if(op[i]==2){
                ll c=x[i]+y[i];
                seg.chg(1,c,e[i]);
            }
        }
        rep(i,0,2*n)val[i]=0;
        rep(i,1,q){
            if(op[i]==2)continue;
            ll b=y[i]-x[i];
            val[b+n]+=e[i];
            ans=max(ans,val[b+n]);
        }
        ans=max(ans,seg.cnt(1,0,2*n));
        rep(i,1,q){
            if(op[i]==2)continue;
            ll b=y[i]-x[i];
            ll l=max(-b,b),r=min(2*n-b,2*n+b);
            ans=max(ans,val[b+n]+seg.cnt(1,l,r));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//x+b=-x+c
//2x=c-b
//0<=c-b<=2*n
//b<=c<=2*n+b
//x=(c-b)/2
//y=x+b=(c+b)/2
//0<=c+b<=2*n
//-b<=c<=2*n-b
//max(-b,b)<=c<=min(2*N-b,2*N+b)
