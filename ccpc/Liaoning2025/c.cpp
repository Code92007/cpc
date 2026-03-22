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
const int N=505,INF=505;
int n,vis[8],dp[N][3];
vector<int>now;
int add(int x,int y){
    rep(i,0,2){
        if((x>>i&1)&&(y>>i&1))return 0;
    }
    return 1;
}
int main(){
    sci(n);
    rep(i,1,n){
        int v,w=0;
        rep(j,0,2){
            sci(v);
            w=w*2+v;
        }
        vis[w]++;
    }
    rep(i,1,7){
        if(vis[i])now.pb(i);
    }
    int ans=n*3,m=now.size();
    do{
        int w=0,all=0,c=0;
        rep(i,0,2)dp[0][i]=1;
        for(auto &v:now){
            c++;
            rep(i,0,2){
                dp[c][i]=INF;
                if(v>>i&1){
                    rep(j,0,2){
                        dp[c][i]=min(dp[c][i],dp[c-1][j]+(i!=j));
                    }
                }
            }
        }
        rep(i,0,2)ans=min(ans,dp[c][i]);
    }while(next_permutation(now.begin(),now.end()));
    pte(ans);
    return 0;
}