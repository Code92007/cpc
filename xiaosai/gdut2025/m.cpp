//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=1e6+10,mod=1e9+7;
int t,n;
P a[N];
bool cmp(P a,P b){
    ll x1=1ll*b.fi*a.se+b.se,x2=1ll*a.fi*b.se+a.se;
    if(x1!=x2)return x1>x2;
    return a.fi<b.fi;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i].fi),sci(a[i].se);
        }
        sort(a+1,a+n+1,cmp);
        ll x=0;
        rep(i,1,n){
            x=(1ll*x*a[i].fi%mod+a[i].se)%mod;
        }
        ptlle(x);
    }
    return 0;
}
//x+b=-x+c
//2x=c-b
//0<=c-b<=2*n