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
typedef array<ll,3> A;
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
const int N=1e6+10;
int t,n,m;
int modpow(int x,ll n,int mod){
    int res=1;
    for(;n;n/=2,x=1ll*x*x%mod){
        if(n&1)res=1ll*res*x%mod;
    }
    return res;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        ll v=1ll*(n-1)*(n-2)/2,ans;
        if(n==1)ans=1%m;
        else if(n==2)ans=2%m;
        else{
            if(n%2==0)v++;
            ans=modpow(2,v,m);
        }
        printf("%lld\n",ans);
    }
    return 0;
}