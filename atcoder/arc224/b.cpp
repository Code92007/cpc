//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
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
using namespace std;
int t;
ll n;
ll sol(){
    ll l=1,r=sqrt(n);
    l=max(r-20,1ll);
    ll ans=0;
    for(ll x=l;x<=r;++x){
        ll y=(n+x-1)/x;
        ll z=n-(x+y-1);
        ll res=2ll*z+x+y-2;
        //printf("n:%lld x:%lld y:%lld z:%lld res:%lld\n",n,x,y,z,res);
        ans=max(ans,res);
    }
    return ans;
}
int main(){
    sci(t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n",sol());
    }
    return 0;
}