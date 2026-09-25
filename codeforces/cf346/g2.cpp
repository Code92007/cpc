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
const int N=1e6+10,mod=1e9+7;
int n,h[N],f[N][2],ans;//f[i][0]表示到i的时候已经结束的方案 f[i][1]表示还没结束的方案
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    sci(n);
    rep(i,1,n){
        sci(h[i]);
        h[i]--;
    }
    h[n+1]=h[n];
    rep(i,1,n){
        f[i][0]=(1ll*f[i-1][1]*min(h[i-1],h[i])%mod+h[i])%mod;
        f[i][1]=(1ll*f[i-1][1]*min({h[i-1],h[i],h[i+1]})%mod+min(h[i],h[i+1]))%mod;
        add(ans,f[i][0]);
    }
    printf("%d\n",ans);
    return 0;
}