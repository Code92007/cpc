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
using namespace std;
const int N=2e5+10;
const ll INF=1e11;
int n,a[N];
ll dp[N];
//dp[i]表示从只能选[i,n]的前缀和时，先手方为了最优能得到的最优得分
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        a[i]+=a[i-1];
    }
    dp[n]=a[n];
    per(i,n-1,1){
        dp[i]=dp[i+1];
        if(i>1)dp[i]=max(dp[i],a[i]-dp[i+1]);
    }
    printf("%lld\n",dp[1]);
    return 0;
}