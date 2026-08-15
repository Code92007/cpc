//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
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
const int N=2e3+10;
int n,a[N];
db sum=1e18;
int main(){
    sci(n);
    rep(i,1,n)sci(a[i]);
    sort(a+1,a+n+1);
    rep(k,0,n-1){
        db ans=0;
        vector<db>y;
        rep(x,1,k){
            y.pb(k-x+1+(n-k)/2.0);
        }
        rep(x,1,n-k){
            y.pb(n-k-x+1);
        }
        sort(y.begin(),y.end(),greater<db>());
        rep(j,0,n-1){
            ans+=y[j]*a[j+1];
        }
        sum=min(sum,ans);
    }
    printf("%.1lf\n",sum);
    return 0;
}