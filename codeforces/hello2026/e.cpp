#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
#define ull unsigned long long
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
const int N=3e3+10,mod=998244353;
int t,n,m,a[N],dp[N][N];
vector<int>nex[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
int sol(){
    if(a[1]>1)return 0;
    if(a[2]!=0 && a[2]!=2)return 0;
    dp[2][2]=1;
    for(int i=2;i<n;++i){
        for(int j=1;j<=m;++j){
            if(!dp[i][j])continue;
            for(auto &v:nex[j]){
                if(v>m)continue;
                if(a[i+1]!=0 && a[i+1]!=v)continue;
                add(dp[i+1][v],dp[i][j]);
            }
        }
    }
    int ans=0;
    for(int j=1;j<=m;++j){
        add(ans,dp[n][j]);
    }
    return ans;
}
int gcd(int a,int b){
    return !b?a:gcd(b,a%b);
}
int lcm(int a,int b){
    int g=gcd(a,b);
    return a/g*b;   
}
int main(){
    rep(a,1,3000){
        rep(b,a+1,3000){
            int l=lcm(a,b);
            if(l/a==l/b+1){
                nex[a].pb(b);
                // printf("a:%d b:%d\n",a,b);
            }
        }
    }
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,n){
            sci(a[i]);
        }
        rep(i,1,n){
            rep(j,1,m){
                dp[i][j]=0;
            }
        }
        pte(sol());
    }
    return 0;
}