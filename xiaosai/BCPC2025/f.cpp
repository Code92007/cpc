#include<bits/stdc++.h>
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
const int N=2e5+10,mod=998244353;
int t,n,k,c[N],ans,sum,a,e;
int modpow(int x,int n,int mod){
    int res=1;
    for(;n;n/=2,x=1ll*x*x%mod){
        if(n&1)res=1ll*res*x%mod;
    }
    return res;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        ans=sum=a=0;
        rep(i,1,n){
            sci(c[i]);
            sum=(sum+c[i])%mod;
        }
        rep(i,1,n){
            if(i==k)c[i]++;
            int prob=1ll*c[i]*modpow(sum+c[i],mod-2,mod)%mod;
            a=(a+prob)%mod;
        }
        int dom=1ll*(mod+1-a)*(sum+c[k])%mod;
        e=1ll*sum*modpow(dom,mod-2,mod)%mod;
        printf("%d\n",e);
    }
    return 0;
}