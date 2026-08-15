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
const int N=140005,INF=0x3f3f3f3f;
int t,n,f[N],dp[N],a[N],b[N][20];
int main(){
    f[1]=1;
    int up=131072;
    rep(i,2,up){
        if(i%2==0)f[i]=f[i/2]+1;
        else f[i]=f[i-1]+1;
    }
    per(i,up,1){
        if(i==up)dp[i]=f[i];
        else dp[i]=min(f[i],dp[i+1]+1);
    }
    sci(t);
    while(t--){
        sci(n);
        ll sum=0;
        rep(i,1,n){
            rep(j,0,16){
                b[i][j]=INF;
            }
        }
        rep(i,1,n){
            sci(a[i]);
            sum+=dp[a[i]];
            rep(k,0,16){
                int w=1<<k;
                int l=(a[i]+w-1)/w*w,r=min(l+40*w,up);
                for(int j=l;j<=r;j+=w){
                    b[i][k]=min(b[i][k],j-a[i]+f[j/w]);
                }
            }
        }
        rep(k,0,16){
            ll tmp=k;
            rep(i,1,n){
                tmp+=b[i][k];
            }
            sum=min(sum,tmp);
        }
        printf("%lld\n",sum);
    }
    return 0;
}