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
const int N=1e6+10;
int t,n,a[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,0,n-1){
            sci(a[i]);
        }
        sort(a+1,a+n);
        rep(i,1,n-1){
            if(a[0]>=a[i])continue;
            a[0]=(a[0]+a[i]+1)/2;
        }
        pte(a[0]);
    }
    return 0;
}