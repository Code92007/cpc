#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;
#define ull unsigned long long
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
int t;
ll a,b,ca,cb,fa;
bool ok(ll x){
    ll all=b+x;
    ll w=all/cb;
    //printf("x:%lld w:%lld ")
    if(w>=fa/ca){
        if(w*ca>=fa)return 1;
    }
    return 0;
}
int main(){
    sci(t);
    while(t--){
        scanf("%lld%lld%lld%lld%lld",&a,&b,&ca,&cb,&fa);
        if(a>=fa){
            puts("0");
            continue;
        }
        fa-=a;
        if(cb<=ca){
            fa-=(b/cb)*ca;
            if(fa<=0)puts("0");
            else{
                b%=cb;
                printf("%lld\n",fa+cb-1-b);
            }
            continue;
        }
        ll l=0,r=1e18,ans;
        while(l<=r){
            ll mid=(l+r)/2;
            if(ok(mid))ans=mid,r=mid-1;
            else l=mid+1;
        }
        if(!ans){
            puts("0");
            continue;
        }
        //printf("ans:%lld ans2:%lld\n",ans,ans2);
        if((ans-1+b)/cb*ca<=fa){
            ll w=(ans-1+b)/cb*ca;
            fa-=w;
            ll ans2=fa+ans-1;
            ans=max(ans,ans2);
        }
        //ans+=cb-1-w;
        printf("%lld\n",ans);
    }
    return 0;
}