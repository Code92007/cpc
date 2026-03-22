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
typedef pair<int,int> P;
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
const int N=2e5+10;
int t,n,a[N];
ll sol(){
    if(n>=4){
        int mx=0;
        rep(i,1,n){
            mx=max(mx,a[i]);
        }
        return 1ll*n*mx;
    }
    if(n==2){
        return max(1ll*a[1]+a[2],2ll*abs(a[2]-a[1]));
    }
    ll sum=0;
    rep(i,1,3){
        sum+=a[i];
    }
    sum=max(sum,3ll*a[1]);
    sum=max(sum,3ll*a[3]);
    sum=max(sum,3ll*abs(a[3]-a[1]));
    sum=max(sum,3ll*abs(a[2]-a[1]));
    sum=max(sum,3ll*abs(a[3]-a[2]));
    return sum;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n)sci(a[i]);
        printf("%lld\n",sol());
    }
    return 0;
}