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
const int N=1e5+10;
int t,n,k,a[N];
int main(){
    sci(t);
    while(t--){
        sci(n);sci(k);
        rep(i,1,n)sci(a[i]);
        ll ans=0;
        if(2*k<=n){
            int r=n-k+1;
            rep(i,k,r)ans+=a[i];
            rep(i,1,k-1)ans+=max(a[i],a[n+1-i]);
        }
        else{
            rep(i,k,n)ans+=max(a[i],a[n+1-i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}