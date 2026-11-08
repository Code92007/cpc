//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=1e6+10,INF=0x3f3f3f3f;
int t,x,y,k;
vector<int>fac[N];
//x先缩到gcd 然后扩到y 一定是最优的 
//因为缩和扩的过程分别是除和乘 且没有公共因子 所以1、2操作是独立的
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int cal(int x,int k){
    auto a=fac[x];
    int m=a.size();
    vector<int>dp(m,INF);
    dp[0]=0;
    for(int i=1;i<m;++i){
        for(int j=0;j<i;++j){
            if(a[i]%a[j]==0 && a[i]/a[j]<=k){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[m-1];
}
int main(){
    for(int i=1;i<N;++i){
        for(int j=i;j<N;j+=i){
            fac[j].push_back(i);
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&x,&y,&k);
        int g=gcd(x,y);
        x/=g,y/=g;
        int ans=cal(x,k)+cal(y,k);
        if(ans>=INF)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}