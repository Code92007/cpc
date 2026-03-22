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
const int N=6e5+10,M=66,K=63,mod=998244353;
int n,m,op,v,two[N],cnt[M],now[M],sum[M],sum2[M];
int Finv[N],fac[N],inv[N];
ll x;
int modpow(int x,int n,int mod){
	int res=1;
	for(;n;x=1ll*x*x%mod,n>>=1)
	if(n&1)res=1ll*res*x%mod;
	return res;
}
void init(int n){ //n<N
    two[0]=1;
    rep(i,1,n)two[i]=2ll*two[i-1]%mod;
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
int cal(ll x){
    rep(i,0,K){
        if(x>>i&1)now[i]=1;
        else now[i]=0;
        sum[i]=cnt[i];
        if(i)sum[i]+=sum[i-1];
    }
    int cur=0;
    per(i,K,0){
        if(now[i]){
            now[i]--;
            now[i+cur]++;
            cur++;
        }
    }
    int left=1,ans=0;
    per(i,K,0){
        int right=(i==0?1:two[sum[i-1]]);
        //mid=C(cnt[i],now[i]+1)+...+C(cnt[i],cnt[i])
        int mid=two[cnt[i]];
        int up=(i==0?now[i]-1:now[i]);//i=0时可以相等
        rep(j,0,up){
            mid=(mid-C(cnt[i],j)+mod)%mod;
        }
        ans=(ans+1ll*left*mid%mod*right%mod)%mod;
        left=1ll*left*C(cnt[i],now[i])%mod;
    }
    return ans;
}
int main(){
    init(N-5);
    sci(n),sci(m);
    rep(i,1,n){
        sci(v);
        cnt[v]++;
    }
    while(m--){
        sci(op);
        scanf("%lld",&x);
        if(op==1)cnt[x]++;
        else if(op==2)cnt[x]--;
        else printf("%d\n",cal(x));
    }
    return 0;
}