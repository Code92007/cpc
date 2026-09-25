//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
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
#define scll(a) scanf("%lld",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=3e5+10,INF=0x3f3f3f3f;
int t,n,dp[N][7];
char s[N];
int sol(){
    // if(s[1]=='0')return -1;
    // rep(i,1,n-1){
    //     if(s[i]=='0' && s[i+1]=='0')return -1;
    // }
    rep(i,0,n){
        rep(j,0,6){
            dp[i][j]=INF;
        }
    }
    dp[0][3]=0;
    rep(i,0,n-1){
        rep(j,0,6){
            if(dp[i][j]==INF)continue;
            int w=j-3;
            rep(nw,-3,3){
                char x=s[i+1];
                if(x=='+' && nw<=0)continue;
                if(x=='-' && nw>=0)continue;
                if(x=='0' && nw)continue;
                if(nw==w)continue;
                int v=max(dp[i][j],abs(nw-w));
                int p=nw+3;
                dp[i+1][p]=min(dp[i+1][p],v);
            }
        }
    }
    int ans=INF;
    rep(i,0,6){
        ans=min(ans,dp[n][i]);
    }
    if(ans==INF)ans=-1;
    return ans;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        pte(sol());
    }
    return 0;
}