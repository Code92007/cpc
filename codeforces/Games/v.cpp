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
typedef pair<int,int> P;
#define fi first
#define se second
#define pb push_back
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
using namespace std;
const int N=7e3+10;
int n,k[2],s[2][N];
int dp[N][2]; // 0=Lose, 1=Win, 2=Loop
int in[N][2]; // 每个状态还未确定的后继数量
queue<P>q;
int main(){
    memset(dp,-1,sizeof dp);
    sci(n);
    rep(j,0,1){
        sci(k[j]);
        rep(i,1,k[j]){
            sci(s[j][i]);
        }
    }
    rep(u,1,n){
        rep(op,0,1){
            in[u][op]=k[op];
        }
    }
    dp[1][0]=dp[1][1]=0;
    q.push({1,0});
    q.push({1,1});
    while(!q.empty()){
        P now=q.front();
        q.pop();
        int u=now.fi,op=now.se;
        if(dp[u][op]==1){
            rep(x,1,k[op^1]){
                int v=u-s[op^1][x];
                if(v<=0)v+=n;
                in[v][op^1]--;
                if(in[v][op^1]==0 && dp[v][op^1]==-1){
                    dp[v][op^1]=0;
                    q.push({v,op^1});
                }
            }
        }
        else{ 
            rep(x,1,k[op^1]){
                int v=u-s[op^1][x];
                if(v<=0)v+=n;
                if(dp[v][op^1]==-1){
                    dp[v][op^1]=1;
                    q.push({v,op^1});
                }
            }
        }
    }
    rep(i,1,n){
        rep(op,0,1){
            if(dp[i][op]==-1){
                dp[i][op]=2;
            }
        }
    }
    rep(op,0,1){
        rep(i,2,n){
            printf("%s%c", dp[i][op]==0?"Lose":(dp[i][op]==1?"Win":"Loop"), " \n"[i==n]);
        }
    }
    return 0;
}