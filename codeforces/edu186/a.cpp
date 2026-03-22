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
const int N=2e5+10;
int p,px,py,qx,qy,a[N];
db dis;
ll sq(ll x){
    return x*x;
}
bool sol(){
    sci(px),sci(py),sci(qx),sci(qy);
    ll sum=sq(px-qx)+sq(py-qy),sum2=0;
    rep(i,1,n){
        sci(a[i]);
        sum2+=a[i];
    }
    sum2=1ll*sum2*sum2;
    if(sum2<sum)return 0;
    sort(a+1,a+n+1);
    ll now=a[n];
    per(i,n-1,1)now-=a[i];
    if(now<=0)return 1;
    now=1ll*now*now;
    if(now>sum)return 0;
    return 1;
}
int main(){
    sci(t);
    while(t--){
        puts(sol());
    }
    return 0;
}
