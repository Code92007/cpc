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
const int N=1e5+10;
int t,n,x;
ll a[N];
bool can[N];
bool ok(int d){
    rep(i,1,n)can[i]=0;
    ll las=-1e9;
    int now=x;
    rep(i,1,n){
        if(i>1 && a[i]-a[i-1]<=d)can[i]=1;
        if(i<n && a[i+1]-a[i]<=d)can[i]=1;
        if(a[i]-las<=d)can[i]=1;
        if(!can[i]){
            if(now)now--;
            else return 0;
            las=a[i]+d;
        }
        else{
            las=a[i];
        }
    }
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(x);
        rep(i,1,n)scanf("%lld",&a[i]);
        int l=1,r=1e9,ans=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            if(ok(mid))ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}