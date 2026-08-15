#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
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
#define pb push_baused
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
const int N=2e5+10;
const ll INF=1e18;
struct Item{
    ll v,w,k;
    friend bool operator<(Item a,Item b){
        return a.v*b.w>b.v*a.w;
    }
}a[N];
int n;
ll c,dp[9],used[N],res,ans;

int main(){
    scanf("%d%lld",&n,&c);
    rep(i,0,n-1){
        scanf("%lld%lld%lld",&a[i].w,&a[i].v,&a[i].k);
    }
    sort(a,a+n);
    res=0;
    bool all=true;
    rep(i,0,n-1){
        ll d=min(a[i].k,c/a[i].w);
        res+=d*a[i].v;
        c-=d*a[i].w;
        used[i]=d;
        if(d!=a[i].k){
            all=false;
            break;
        }
    }
    if(all){
        printf("%lld\n",res);
        return 0;
    }
    rep(i,0,8) {
        dp[i]=-INF;
    }
    dp[8-c]=res;
    rep(i,0,n-1){
        rep(j,0,8){
            rep(t,1,used[i]){
                if(j-t*a[i].w<0) break;
                dp[j-t*a[i].w]=max(dp[j-t*a[i].w],dp[j]-t*a[i].v);
            }
        }
    }
    rep(i,0,n-1){
        per(j,8,0){
            rep(t,1,a[i].k-used[i]){
                if(j+t*a[i].w>8) break;
                dp[j+t*a[i].w]=max(dp[j+t*a[i].w],dp[j]+t*a[i].v);
            }
        }
    }
    ans=-INF;
    rep(i,0,8) {
        ans=max(ans,dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}