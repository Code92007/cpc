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
const int N=1e5+10,M=(1<<18)+5;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int t,n,c,a[N];
ll dp[N],g[M];
//dp[i]=min(dp[i],dp[j]+(i-j-1)*c+(ai^aj),1<=j<i)
////dp[i]=min(dp[i],dp[j]-(j+1)*c+i*c+(ai^aj),1<=j<i)
ll sol(){
    memset(g,INF,sizeof g);
    memset(dp,INF,sizeof dp);
    a[0]=0;
    a[++n]=0;
    dp[0]=0;
    g[0]=-c;
    int bit=1<<9,mask=(1<<9)-1;
    for(int i=0;i<bit;++i){
        g[i]=g[0]+i;
    }
    rep(i,1,n){
        int high=a[i]>>9,low=a[i]&mask;
        for(int j=0;j<bit;++j){
            int highxor=high^j,val=(j<<9)|low;
            dp[i]=min(dp[i],1ll*i*c+g[val]+(highxor<<9));
        }
        for(int j=0;j<bit;++j){
            int lowxor=low^j,val=(high<<9)|j;
            g[val]=min(g[val],dp[i]-1ll*(i+1)*c+lowxor);
        }
    }
    return dp[n];
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(c);
        rep(i,1,n)sci(a[i]);
        printf("%lld\n",sol());
    }
    return 0;
}
/*
3
4 4
1 4 5 6
8 6
6 6 6 1 1 6 6 6
6 7
1 7 2 6 3 5
*/