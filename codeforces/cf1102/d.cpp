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
typedef pair<ll,int> P;
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
const int N=1e5+10;
typedef array<ll,3> A;
int t,n,k;
char s[N],w[N];
map<A,A>dp;
A cal(int l,int r,int k){
    if(k==1){
        A x={0,0,0};
        x[l-1]++;
        x[r-1]++;
        x[(l^r)-1]++;
        //printf("l:%d r:%d k:%d ans:(%d,%d,%d)\n",l,r,k,x[0],x[1],x[2]);
        return x;
    }
    if(dp.count({l,r,k}))return dp[{l,r,k}];
    A ans={0,0,0};
    A x=cal(l,l^r,k-1),y=cal(l^r,r,k-1);
    rep(i,0,2){
        ans[i]+=x[i];
        ans[i]+=y[i];
    }
    ans[(l^r)-1]--;
    //printf("l:%d r:%d k:%d ans:(%d,%d,%d)\n",l,r,k,ans[0],ans[1],ans[2]);
    return dp[{l,r,k}]=ans;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        scanf("%s",s+1);
        scanf("%s",w+1);
        A x=cal(1,2,k);
        int cnt=0,cnt2=0,cnt3=0;
        rep(i,1,n){
            if(s[i]=='1')cnt++;
            if(w[i]=='1')cnt2++;
            if(s[i]==w[i])cnt3++;
        }
        printf("%lld\n",1ll*cnt*(n-cnt)*x[0]+1ll*cnt2*(n-cnt2)*x[1]+1ll*cnt3*(n-cnt3)*x[2]);
    }
    return 0;
}
/*
(0,1) (1,0) (1,1) (0,1) (1,0)
*/