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
const int N=110,M=2e3+10;
int n,x,y,t,a[N],b[N],dp[N][M],g[N][M],used[N];
int main(){
    sci(n),sci(x),sci(y),sci(t);
    rep(i,1,n)sci(a[i]);
    rep(i,1,n)sci(b[i]);
    rep(i,1,n){
        rep(j,0,t){
            if(dp[i][j]<dp[i-1][j]){
                dp[i][j]=dp[i-1][j];
                g[i][j]=0;
            }
            rep(k,1,a[i]){
                int p=j+x+k*y;
                if(p>t)break;
                if(dp[i][p]<dp[i-1][j]+k*b[i]){
                    dp[i][p]=dp[i-1][j]+k*b[i];
                    //printf("i:%d p:%d dp:%d\n",i,p,dp[i][p]);
                    g[i][p]=k;
                }
            }
        }
    }
    int ans=0,st=0;
    rep(i,0,t){
        if(ans<dp[n][i]){
            ans=dp[n][i];
            st=i;
        }
    }
    //printf("ans:%d\n",ans);
    per(i,n,1){
        int k=g[i][st];
        //printf("i:%d k:%d st:%d\n",i,k,st);
        used[i]=k;
        if(k)st=st-k*y-x;
    }
    rep(i,1,n){
        printf("%d%c",used[i]," \n"[i==n]);
    }
    return 0;
}