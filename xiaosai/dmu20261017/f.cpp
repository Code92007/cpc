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
const int N=15,M=5e5+10,INF=0x3f3f3f3f,mod=998244353;
int n,k,w[N][N],xs,bs[N],tmp[N];
int dp[M][N];
int main(){
    sci(n),sci(k);
    rep(i,0,n-1){
        rep(j,i+1,n-1){
            sci(w[i][j]);
            w[j][i]=w[i][j];
        }
    }
    xs=k+1;
    bs[0]=1;
    rep(i,1,n){
        bs[i]=1ll*bs[i-1]*xs;
    }
    memset(dp,INF,sizeof dp);
    dp[0][0]=0;
    int up=bs[n]-1;
    rep(i,0,up){
        int v=i;
        rep(j,0,n-1){
            tmp[j]=v%xs;
            v/=xs;
        }
        rep(j,0,n-1){
            if(dp[i][j]==INF)continue;
            rep(l,0,n-1){
                if(j==l)continue;
                if(tmp[l]>=k)continue;
                int ni=i+bs[l];
                dp[ni][l]=min(dp[ni][l],dp[i][j]+w[j][l]);
            }
        }
    }
    printf("%d\n",dp[up][0]);
    return 0;
}