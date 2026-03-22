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
const int N=1e6+10;
int t,n,m,k,a[N],b[N],id[N],x[N],c;
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
}seg,seg2;//v-i,v+i
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m),sci(k);
        c=0;
        rep(i,1,k){
            id[i]=i;
            sci(a[i]),sci(b[i]);
            x[c++]=b[i];
        }
        sort(id+1,id+k+1,[&](int u,int v)){
            return a[u]<a[v];
        }
        ll ans=n+1;
        rep(i,1,k){
            int v=id[i];

        }
    }
    return 0;
}
/*
n=1 2*2 [1,1]
1 0
0 1

n=2 4*4 [1,16]
0 2 0 0
1 1 0 0
0 0 0 4
0 0 8 0

n=3 6*6 [1,81]
1 0 2 0 4  
0 2 0 4 0  1
2 0 4 0 2  0
0 4 0 8 0  0
4 0 0 0 16 0
0 0 0 0 0  
*/