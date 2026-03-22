//#include <bits/stdc++.h>
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
const int N=1e6+10,M=2e6+10,INF=1e9;
int n,c,ans;
P a[N];
ll x;
bool cmp(P x,P y){
	if(max(x.fi,x.se)==max(y.fi,y.se)){
		if(x.fi<x.se && y.fi>y.se)return 1;
	}
	return max(x.fi,x.se)<max(y.fi,y.se);
}
int main(){
    sci(n);
    rep(i,1,n){
        scanf("%lld%lld",&a[i].fi,&a[i].se);
    }
    sort(a+1,a+n+1,cmp);
    rep(i,1,n){
		if(x<=a[i].fi){
			x=max(x,a[i].se);
			ans++;
		}
    }
    printf("%d\n",ans);
    return 0;
}