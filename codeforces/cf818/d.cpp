//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
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
const int N=1e5+10,mod=1e9+7;;
int n,k,Finv[N],fac[N],inv[N],ans;
int modpow(int x,int n,int mod){
	int res=1;
	for(;n;x=1ll*x*x%mod,n>>=1)
	if(n&1)res=1ll*res*x%mod;
	return res;
}
void init(int n){ //n<N
    inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=Finv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod,Finv[i]=1ll*Finv[i-1]*inv[i]%mod;
	//Finv[n]=modpow(fac[n],mod-2,mod);
	//for(int i=n-1;i>=1;--i)Finv[i]=1ll*Finv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	if(m<0||m>n)return 0;
	return 1ll*fac[n]*Finv[n-m]%mod*Finv[m]%mod;
}
int main(){
    init(N-5);
    sci(n),sci(k);
    k=min(n,k);
    if(k>=n){
        pte(modpow(2,n,mod));
        return 0;
    }
    rep(i,0,k){
        ans=(ans+C(n,i))%mod;
    }
    pte(ans);
    return 0;
}