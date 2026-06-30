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
ll n,m,R[N],c[N];
bool ok(ll x){
    __int128 sum=0;
    rep(i,1,m){
        //(t-1)*x+t<=c
        //tx-x+t<=c t(x+1)<=c+x
        ll t=(1ll*c[i]+x)/(1ll*x+1);
        t=min(t,c[i]);
        t=max(t,1ll);
        //printf("x:%d i:%d t:%d\n",x,i,t);
        ll v=1ll*t*R[i];
        if(v>=n)return 1;
        sum+=v;
        if(sum>=n)return 1;
    }
    return 0;
}
int main(){
    scanf("%lld%lld",&n,&m);
    rep(i,1,m){
        scanf("%lld%lld",&R[i],&c[i]);
    }
    ll l=0,r=1e9,ans=1e9;
    while(l<=r){
        ll mid=(l+r)/2;
        if(ok(mid))l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}