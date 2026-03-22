#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;#include<bits/stdc++.h>
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
int t,n,k,v,f[N],dp[N][N],vis[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    sci(t);
    while(t--){
        sci(n);sci(k);
        rep(i,0,n){
            vis[i]=0;
            f[i]=0;
            rep(j,0,n){
                dp[i][j]=0;
            }
        }
        rep(i,1,k){
            sci(v);
            vis[v]=1;
        }
        f[1]=1;
        dp[1][0]=1;
        rep(i,2,n){
            rep(j,1,i-1){
                rep(x,1,i-1){
                    add(dp[i][j],1ll*dp[i-x][j-1]*f[x]%mod);
                }
                if(vis[j]){  
                    add(f[i],dp[i][j]);
                }
            }
        }
        printf("%d\n",f[n]);
    }
    return 0;
}