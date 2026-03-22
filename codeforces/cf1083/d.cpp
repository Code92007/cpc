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
const int N=5e5+10,M=20;
int dp[N][M],lg2[N];
int t,n,a[N];
void ST(int tot){
	for(int i=1;i<=tot;++i){
        dp[i][0]=i;
	}
	for(int len=1;(1<<len)<=tot;++len){
		for(int l=1;l+(1<<len)-1<=tot;++l){
			if(a[dp[l][len-1]]>a[dp[l+(1<<(len-1))][len-1]])dp[l][len]=dp[l][len-1];
			else dp[l][len]=dp[l+(1<<(len-1))][len-1];
		}
	}
}
int RMQ(int l,int r){
	int len=lg2[r-l+1];
	if(a[dp[l][len]]>a[dp[r-(1<<len)+1][len]])return dp[l][len];
	else return dp[r-(1<<len)+1][len];
}
int sol(int l,int r){
    int p=RMQ(l,r);
    if(l==r)return 0;
    if(l==p)return sol(l+1,r);
    if(r==p)return sol(l,r-1);
    return min(sol(l,p-1)+r-p,sol(p+1,r)+p-l);
}
int main(){
    for(int i=2;i<N;++i){
        lg2[i]=lg2[i>>1]+1;
    }
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
        }
        ST(n);
        printf("%d\n",sol(1,n));
    }
    return 0;
}
/* 
2 4 3
1 4 7
7 4 1

1 2 3 4 5
5 4 3 2 1
5 3 1 2 4
*/