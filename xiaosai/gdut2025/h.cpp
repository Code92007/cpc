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
const int N=1e5+10;
int n,a[N],dp[N][2];
void upd(int &x,int y){
    x=max(x,y);
}
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
    }
    rep(i,0,n){
        upd(dp[i+1][0],dp[i][1]+a[i+1]);
        upd(dp[i+2][1],max(dp[i][0],dp[i][1])+a[i+2]);
    }
    pte(max(dp[n][0],dp[n][1]));
    return 0;
}
