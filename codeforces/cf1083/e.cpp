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
const int N=8005,mod=998244353;
int t,n,a[N],nex[N][N],dp[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
void kmppre(int *nex,int *b,int m){
	int i=0,j=nex[0]=-1;
	while(i<m){
		while(j!=-1&&b[i]!=b[j])j=nex[j];
		nex[++i]=++j;
	}
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            dp[i]=0;
            sci(a[i]);
        }
        rep(i,1,n){
            kmppre(nex[i],a+i,n+1);
        }
        dp[0]=1;
        rep(i,1,n){
            per(j,i-1,0){//[j+1,i]
                int l=j+1;
                if(!nex[l][i-l+1]){
                    add(dp[i],dp[j]);
                }
            }
            //printf("i:%d dp:%d\n",i,dp[i]);
        }
        pte(dp[n]);
        // rep(i,1,n){
        //     rep(j,0,n-i+1){
        //         printf("i:%d j:%d nex:%d\n",i,j,nex[i][j]);
        //     }
        // }
    }
    return 0;
}
/*
1 2 3
1 [3 2]
[2 1] 3
[3 2 1]

1 2 3 1
1 [3 2] 1
[2 1] 3 1
[2 1] [1 3]
[3 2 1] 1

1 

1 1 3
1 3 1
3 1 1

3 1 3
1 3 3
3 3 1

1 2 3 2 3
1 3 2 3 2
1 2 3 2 3

1 2 3 1
1 3 2 1

a b c a b c
*/