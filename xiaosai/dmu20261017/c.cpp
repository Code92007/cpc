//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
int n;
ll sum,ans,x;
map<ll,int>mp;
int main(){
    sci(n);
    scanf("%lld",&x);
    mp[0]=1;
    rep(i,1,n){
        ll v;
        scanf("%lld",&v);
        sum+=v;
        ll w=sum-1ll*x*i;
        ans+=mp[w];
        mp[w]++;
        if(v==x)ans--;
    }
    ptlle(ans);
    return 0;
}
//sum[r]-sum[l-1]=x*(r-(l-1))
//sum[r]-sum[l-1]=x*r-x*(l-1)