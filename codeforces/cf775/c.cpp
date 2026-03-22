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
const int N=2e5+10,M=2e5,mod=998244353;
int n,m,s[N],t[N],cnt[N];
int Finv[N],fac[N],inv[N];
void init(int n){ //n<N
    inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=Finv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod,Finv[i]=1ll*Finv[i-1]*inv[i]%mod;
	//Finv[n]=modpow(fac[n],mod-2,mod);
	//for(int i=n-1;i>=1;--i)Finv[i]=1ll*Finv[i+1]*(i+1)%mod;
}
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
        if(ql>qr)return;
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
}tr;
int main(){
    init(M);
    sci(n),sci(m);
    rep(i,1,n)sci(s[i]);
    rep(i,1,m)sci(t[i]);
    rep(i,1,n){
        cnt[s[i]]++;
    }
    int p=min(n,m),pos=p-1,ans=0;
    rep(i,1,pos){
        if(cnt[t[i]]>0)cnt[t[i]]--;
        else{
            p=i;
            break;
        }
    }
    if(n<m && p==n && cnt[t[p]]==1){
        ans=1;
    }
    //printf("p:%d\n",p);
    int all=0,w=1;
    tr.init(M);
    rep(i,1,M){
        if(cnt[i]){
            //printf("i:%d cnt:%d\n",i,cnt[i]);
            all+=cnt[i];
            w=1ll*w*Finv[cnt[i]]%mod;
        }
    }
    rep(i,1,M){
        if(cnt[i]){
            int v=1ll*w*fac[cnt[i]]%mod;
            v=1ll*v*Finv[cnt[i]-1]%mod;
            //printf("i:%d w:%d\n",1ll*fac[all-1]*v%mod);
            tr.chg(1,i,1ll*fac[all-1]*v%mod);
        }
    }
    per(i,p,1){
        ans=(ans+tr.cnt(1,1,t[i]-1))%mod;
        if(i==1)break;
        int v=t[i-1];
        w=1ll*w*fac[cnt[v]]%mod;
        cnt[v]++;
        w=1ll*w*Finv[cnt[v]]%mod;
        int x=1ll*all*inv[cnt[v]]%mod;
        //printf("v:%d all:%d cnt:%d x:%d\n",v,all,cnt[v],x);
        tr.mul(1,1,v-1,x);
        tr.mul(1,v+1,M,x);
        int w2=1ll*all*inv[cnt[v]-1]%mod;
        //printf("i:%d all:%d w:%d\n",i,all,1ll*fac[all]*w%mod);
        if(cnt[v]==1)tr.chg(1,v,1ll*fac[all]*w%mod);
        else tr.mul(1,v,v,w2);
        all++;
        ///tr.mul(1,t[i-1]);//*all /3! /4!
    }
    printf("%d\n",ans);
    return 0;
}