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
typedef pair<int,int> P;
typedef array<int,3> A;
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
int t,n;
ll h,k,a[N],mx[N],mn[N],sum[N];
ll sol(){
    ll ans=0;
    ll v=sum[n];
    if(h>=v){
        ll x=h/v;
        if(h%v==0){
            return 1ll*(x-1)*k+1ll*x*n;
        }
        else{
            ans+=1ll*x*k+1ll*x*n;
            h%=v;
        }
    }
    int y=n,z=n;
    per(i,n,1){
        if(i==n)mx[i]=a[i];
        else mx[i]=max(mx[i+1],a[i]);
    }
    rep(i,1,n){
        if(sum[i]>=h){y=min(y,i);}
        if(i==1)mn[i]=a[i];
        else mn[i]=min(mn[i-1],a[i]);
    }
    rep(i,1,n-1){
        if(sum[i]-mn[i]+mx[i+1]>=h){z=min(z,i);}
    }
    return ans+min(y,z);
}
int main() {
    sci(t);
    while(t--){
        sci(n);
        scanf("%lld%lld",&h,&k);
        rep(i,1,n){
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        ptlle(sol());
    }
    return 0;
}