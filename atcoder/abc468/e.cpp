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
const int N=5e5+10,mod=998244353;
int n,a[N],inv[N],sum[N];
int ans;
int modpow(int x, int n, int mod) {
    int res = 1;
    for (; n; x = 1ll * x * x % mod, n >>= 1)
        if (n & 1) res = 1ll * res * x % mod;
    return res;
}
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        a[i]=(a[i]+a[i-1])%mod;
        inv[i]=modpow(i,mod-2,mod);
        sum[i]=(sum[i-1]+inv[i])%mod;
    }
    rep(i,1,n){
        ans=(ans+1ll*a[i]*sum[i]%mod)%mod;
    }
    rep(i,0,n-1){
        ans=(ans-1ll*a[i]*sum[n-i]%mod)%mod;
        ans=(ans%mod+mod)%mod;
    }
    pte(ans);
    return 0;
}