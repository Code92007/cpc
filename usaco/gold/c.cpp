#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;
#define ull unsigned long long
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
const int N=1e6+10,mod=1e9+7;
int n,d,p[N],o[N];
struct segtree{
	int n;
	struct node{int l,r,v,c;}e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
	#define v(p) e[p].v
	#define c(p) e[p].c
	void up(int p){v(p)=(v(p<<1)+v(p<<1|1))%mod;}
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;c(p)=1;
		if(l==r){v(p)=0;return;}
		int mid=l+r>>1;
		bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
		up(p);
	}
	void init(int _n){n=_n;bld(1,0,n);}
    void psd(int p){
		if(c(p)!=1){
			v(p<<1)=1ll*v(p<<1)*c(p)%mod;
			c(p<<1)=1ll*c(p<<1)*c(p)%mod;
			v(p<<1|1)=1ll*v(p<<1|1)*c(p)%mod;		
			c(p<<1|1)=1ll*c(p<<1|1)*c(p)%mod;
			c(p)=1; 
		}
	}
	void chg(int p,int x,int v){
		if(l(p)==r(p)){v(p)=v;return;}
		int mid=l(p)+r(p)>>1;
        psd(p);
		chg(p<<1|(x>mid),x,v);
		up(p);
    }
    void mul(int p,int ql,int qr,int w){
		if(ql<=l(p)&&r(p)<=qr){
			v(p)=1ll*v(p)*w%mod;
			c(p)=1ll*c(p)*w%mod;
			return;
		}
		psd(p);
		int mid=l(p)+r(p)>>1;
		if(ql<=mid)mul(p<<1,ql,qr,w);
		if(qr>mid)mul(p<<1|1,ql,qr,w);
		up(p);
	}
	int cnt(int p,int ql,int qr){
        if(ql>qr)return 0;
		if(ql<=l(p)&&r(p)<=qr)return v(p);
		int mid=l(p)+r(p)>>1,res=0;
        psd(p);
		if(ql<=mid)res=(res+cnt(p<<1,ql,qr))%mod;
		if(qr>mid)res=(res+cnt(p<<1|1,ql,qr))%mod;
		return res;
	}
}coach;
int main(){
    sci(n),sci(d);
    rep(i,1,n){
        sci(p[i]),sci(o[i]);
    }
    coach.init(n);
    rep(i,1,n){
        if(o[i]==1){//coach
            int w=(coach.cnt(1,1,i)+1)%mod;
            coach.chg(1,i,w);
        }
        else{//camper
            int pos=lower_bound(p+1,p+i+1,p[i]-d)-p;
            coach.mul(1,pos,i,2);
        }
    }
    printf("%d\n",coach.cnt(1,1,n));
    return 0;
}