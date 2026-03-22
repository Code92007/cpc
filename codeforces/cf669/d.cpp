#include<bits/stdc++.h>
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
const int N=3e5+10;
int n,h[N],stk[N],stk2[N],c,c2,dp[N];
vector<int>e[N];
void sol(){
    sci(n);
    rep(i,1,n){
        sci(h[i]);
        while(c && h[stk[c]]>h[i])c--;
        while(c2 && h[stk2[c2]]<h[i])c2--;
        if(c)e[i].pb(stk[c]);
        if(c2)e[i].pb(stk2[c2]);
        stk[++c]=i;
        stk2[++c2]=i;
    }
    c=c2=0;
    per(i,n,1){
        while(c && h[stk[c]]>h[i])c--;
        while(c2 && h[stk2[c2]]<h[i])c2--;
        if(c)e[stk[c]].pb(i);
        if(c2)e[stk2[c2]].pb(i);
        stk[++c]=i;
        stk2[++c2]=i;
    }
    rep(i,1,n){
        dp[i]=dp[i-1]+1;
        for(auto &x:e[i]){
            //printf("i:%d x:%d\n",i,x);
            dp[i]=min(dp[i],dp[x]+1);
        }
    }
    printf("%d\n",dp[n]-1);
}
int main(){
    //int t;sci(t);while(t--){
    sol();
    //}
    return 0;
}
/*
badcase:
5 3 2 4 5

单调栈好题
找到左侧的第一个<=/>=自己的 右侧第一个<=/>=自己的 连边
只能从这些地方转移
*/