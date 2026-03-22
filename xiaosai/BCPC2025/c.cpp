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
const int N=1e5+10,mod=123456789;
int T;
ll n,t;
ll sol(){
    if(n==1)return t;
    if(n==2)return 2ll*t;
    if(n==3)return 3ll*t-2;
    ll ans=4ll*t-4;
    n=min(n,4ll*(t/2-1));
    n-=4;
    ans+=1ll*n*(t/2);
    return ans;
}
int main(){
    sci(T);
    while(T--){
        scanf("%lld%lld",&n,&t);
        printf("%lld\n",sol());
    }
    return 0;
}