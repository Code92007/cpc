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
const int N=1e6+10,mod=1e9+7;
int t,p,n,k,a[N];
int modpow(int x, int n, int mod) {
    int res = 1;
    for (; n; x = 1ll * x * x % mod, n >>= 1)
        if (n & 1) res = 1ll * res * x % mod;
    return res;
}
void sol(){
    if(p==1){
        printf("%d\n",n%2);
        return;
    }
    sort(a+1,a+n+1,greater<int>());
    ll delta=0,INF=2e12,ds=0;
    rep(i,1,n){
        int w=a[i],d=a[i-1]-a[i];
        if(i && delta){
            rep(j,1,d){
                delta*=p;
                if(delta>INF){
                    delta=INF;
                    break;
                }
                if(delta<-INF){
                    delta=-INF;
                    break;
                }
            }
        }
        if(delta<=0){
            delta++;
            ds=(ds+modpow(p,a[i],mod))%mod;
        }
        else{
            delta--;
            ds=(ds+mod-modpow(p,a[i],mod))%mod;
        }
    }
    if(delta<0)ds=(mod-ds)%mod;
    printf("%lld\n",ds);
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(p);
        rep(i,1,n){
            sci(a[i]);
        }
        sol();
    }
    return 0;
}