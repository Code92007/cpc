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
const int N=2e5+10,mod=998244353;
int t,n;
char s[N];
int dp[3][2],pd[3][2];
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        int lb=0,rb=0;
        if(s[1]=='0' || s[1]=='1')lb=rb=s[1]-'0';
        else lb=0,rb=1;
        int l2=0,r2=0;
        if(s[2]=='0' || s[2]=='1')l2=r2=s[2]-'0';
        else l2=0,r2=1;
        memset(dp,0,sizeof dp);
        rep(i,lb,rb){
            rep(j,l2,r2){
                dp[i+j][j]=1;
            }
        }
        rep(j,3,n){
            memset(pd,0,sizeof pd);
            int lb=0,rb=0;
            if(s[j]=='0' || s[j]=='1')lb=rb=s[j]-'0';
            else lb=0,rb=1;
            rep(k,0,2){
                rep(l,0,1){
                    rep(x,lb,rb){
                        if(l+x!=k)add(pd[l+x][x],dp[k][l]);
                    }
                }
            }
            rep(k,0,2){
                rep(l,0,1){
                    dp[k][l]=pd[k][l];
                }
            }
        }
        int ans=0;
        rep(k,0,2){
            rep(l,0,1){
                add(ans,dp[k][l]);
            }
        }
        pte(ans);
    }
    return 0;
}