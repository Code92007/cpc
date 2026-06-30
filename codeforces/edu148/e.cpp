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
const int N=1e7+10,M=6,mod=998244353;
int n,v,x,y,sum,m,k,b[N][M];
ll ans;
int main(){
    sci(n),sci(v),sci(x),sci(y),sci(m),sci(k);
    sum=v;
    rep(i,1,n){
        b[i][1]=(b[i-1][1]+sum)%mod;
        v=(1ll*v*x+y)%m;
        sum=(sum+v)%mod;
    }
    rep(j,2,k){
        rep(i,1,n){
            b[i][j]=(b[i-1][j-1]+b[i-1][j])%mod;
        }
    }
    rep(i,1,n){
        ans^=1ll*b[i][k]*i;
    }
    printf("%lld\n",ans);
    return 0;
}