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
typedef pair<int,int> P;
typedef array<int,3> A;
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
const int N=1e3+10,M=1e6+10;
int n,k,s,a[N],dp[M];
int main(){
    sci(n),sci(k);
    rep(i,1,n){
        sci(a[i]);
    }
    sort(a+1,a+n+1);
    s=a[1]*k;
    rep(i,2,n){
        a[i]-=a[1];
    }
    int up=a[n]*k;
    rep(i,1,up)dp[i]=k+1;
    dp[0]=0;
    rep(i,2,n){
        rep(j,a[i],up){
            dp[j]=min(dp[j],dp[j-a[i]]+1);
        }
    }
    rep(i,0,up){
        if(dp[i]<=k){
            printf("%d ",s+i);
        }
    }
    return 0;
}