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
const int N=5e3+10,M=3*N;
int n,e,dp[N][M];//dp[i][j]表示j时刻位于i时的最大能量数
int a[N],l[N],r[N];
void upd(int &x,int y){
    x=max(x,y);
}
int main(){
    sci(n),sci(e);
    rep(i,1,n){
        sci(a[i]),sci(l[i]),sci(r[i]);
    }
    memset(dp,128,sizeof dp);
    dp[1][0]=e;
    int m=3*n+5;
    rep(i,1,n-1){
        rep(j,0,m){
            if(dp[i][j]<=0)continue;
            //printf("i:%d j:%d dp:%d\n",i,j,dp[i][j]);
            if(j+1<=m){
                if(i==1 && j+1==l[1] && dp[i][j]>1)upd(dp[i][j+1],dp[i][j]+a[1]-1);
                if(dp[i][j]>1)upd(dp[i][j+1],dp[i][j]-1);
            }
            if(j+1<=m){
                if(dp[i][j]>2)upd(dp[i+1][j+1],dp[i][j]-2);
                if(l[i+1]<=j+1 && j+1<=r[i+1] && dp[i][j]>2){
                    upd(dp[i+1][j+1],dp[i][j]-2+a[i+1]);
                }
            }
        }
    }
    int ans=-1;
    rep(j,0,m){
        if(dp[n][j]>2){
            ans=j+1;
            break;
        }
    }
    pte(ans);
    return 0;
}