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
const int N=105,mod=998244353;
int n,dp[N],a[N][N];
bool ban[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    sci(n);
    rep(i,1,n){
        rep(j,i,n){
            sci(a[i][j]);
        }
    }
    dp[0]=1;
    rep(i,1,n){
        rep(j,0,i-1){//枚举上一个不同的字符的位置j
            if(ban[j])continue;
            bool ok=1;
            rep(x,j+1,i){
                if(a[x][i]==2)ok=0;
            }
            rep(y,1,j){
                if(a[y][i]==1)ok=0;
            }
            if(!ok){
                ban[j]=1;
                continue;
            }
            //printf("i:%d j:%d\n",i,j);
            add(dp[i],dp[j]);
        }       
        //printf("i:%d dp:%d\n",i,dp[i]);
    }
    int ans=2ll*dp[n]%mod;
    printf("%d\n",ans);
    return 0;
}