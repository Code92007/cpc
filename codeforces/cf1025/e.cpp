//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
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
#define scll(a) scanf("%lld",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=505,mod=998244353;
int Finv[N],fac[N],inv[N];
int t,n,k,dp[N][N];
char s[N];
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
void add(int &x,int y){
    x=(x+y)%mod;
}
void sol(){
    sci(n),sci(k);
    scanf("%s",s+1);
    memset(dp,0,sizeof dp);
    dp[n][0]=1;
    for(int i=n;i>=1;--i){
        for(int j=0;j<=k;++j){
            if(!dp[i][j])continue;
            add(dp[i-1][j],dp[i][j]);
            for(int l=1;j+l<=k;++l){
                int w;
                if(s[i]=='0')w=C((j+l+1)/2,l);
                else w=C((j+l)/2,l);
                add(dp[i-1][j+l],1ll*dp[i][j]*w%mod);
            }
        }
    }
    printf("%d\n",dp[0][k]);
}
int main(){
    init(N-5);
    sci(t);
    while(t--){
        sol();
    }
}