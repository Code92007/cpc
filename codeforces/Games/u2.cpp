//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define sci(a) scanf("%d",&(a))

const int N=10005, M=35;
int u,v,n;
int dp[N][M];
char s[3][10]={"Stas","Masha","Missing"};

// 判断 u^v >= n，用 long long，提前判断溢出
bool over(int u,int v){
    if(u==1) return false;
    long long res=1;
    rep(i,1,v){
        // 如果 res > n / u，再乘 u 就会超过 n（或溢出）
        if(res > n / u) return true;
        res *= u;
        if(res >= n) return true;
    }
    return false;
}

int dfs(int u,int v){
    int &ans=dp[u][v];
    if(~ans) return ans;
    if(over(u,v)) return ans=0;
    
    // u=1：加物品永远安全
    if(u==1){
        // 尝试加盒子（如果不会立刻输）
        if(!over(2, v)){
            int res = dfs(2, v);
            if(res == 0) return ans=1;  // 加盒子让对手输
        }
        // 否则加物品平局
        return ans=2;
    }
    
    // v==1 特殊优化：加物品会立刻输，只能加盒子
    if(v==1 && over(u, 2)){
        int dis = n - u;
        // dis=1: 当前加一次到 n -> 当前输
        // dis=2: 当前加到 u+1，对手加到 n -> 对手输，当前赢
        if(dis % 2 == 1) return ans=0;
        else return ans=1;
    }
    
    int res1 = dfs(u+1, v);   // 加盒子
    int res2 = dfs(u, v+1);   // 加物品
    
    if(res1==0 || res2==0) return ans=1;
    if(res1==2 || res2==2) return ans=2;
    return ans=0;
}

int main(){
    sci(u); sci(v); sci(n);
    memset(dp,-1,sizeof dp);
    int w=dfs(u,v);
    printf("%s\n", s[w]);
    return 0;
}