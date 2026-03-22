//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
const int N=5e5+10;
int n,m,a[N],b[N],c[N],mx1,mx2;
priority_queue<int,vector<int>,greater<int> >qa; // 还没出的题
priority_queue<int>qb; // 已经验的题
P cal(int k){
    int x=0;
    ll gx=0;
    while(!qa.empty())qa.pop();
    while(!qb.empty())qb.pop();
    for(int i=1;i<=n;++i){
        c[i]=a[i]-k;
        qa.push(c[i]);
        ll cost1=(qb.empty()?0:b[i]-qb.top());
        ll cost2=qa.top()+b[i];
        if(min(cost1,cost2)<0){
            if(cost1<=cost2){//反悔贪心，换成更小的验题，gx相等时出题数更少更优
                qb.pop();
                qb.push(b[i]);
                gx+=cost1;
            }
            else{//新增一题，出题+验题
                qa.pop();
                qb.push(b[i]);
                x++;
                gx+=cost2;
            }
        }
    }
    //printf("k:%d x:%d fx:%lld\n",k,x,gx+1ll*k*x);
    return P(x,gx+1ll*k*x);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        mx1=max(mx1,a[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&b[i]);
        mx2=max(mx2,b[i]);
    }
    int l=0,r=mx1+mx2+1;
    while(l<=r){
        int mid=(r-l)/2+l;
        if(cal(mid).first>m)r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n",cal(r).second);
    return 0;
}
/*
-4 -3
3  2

-4 -4
3  3
*/