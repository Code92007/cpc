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
const int N=5e3+10,M=1e4+10;
char s[N],res[M];
int n,dp[N][N],nex[N][N],lcp[N][N],suf[N][N];
int ans,pos,c;
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    per(i,n,1){
        per(j,n,1){
            if(s[i]==s[j])lcp[i][j]=1+lcp[i+1][j+1];
            else lcp[i][j]=0;
        }
    }
    per(r,n,1){
        per(l,r,1){
            if(r==n){
                dp[l][r]=1;
                nex[l][r]=n+1;
                suf[l][r]=n;
            }
            else{
                suf[l][r]=suf[l][r+1];
                int x=min(r-l+1,lcp[l][r+1]);
                int L=l+x,R=r+1+x;
                //printf("l:%d r:%d L:%d R:%d x:%d\n",l,r,L,R,x);
                if(R<=n){//右串没出界
                    if(L>r || s[L]<s[R]){//左串要么出界 要么比右串小
                        dp[l][r]=1+dp[r+1][suf[r+1][R]];
                        nex[l][r]=suf[r+1][R];
                    }
                }
                if(dp[l][r]>=dp[l][suf[l][r]]){
                    suf[l][r]=r;
                }
            }
            //printf("l:%d r:%d dp:%d\n",l,r,dp[l][r]);   
            if(l==1){
                if(dp[l][r]>ans){
                    ans=dp[l][r];
                    pos=r;
                }
            }
        }
    }
    int l=1,r=pos;
    printf("%d\n",dp[l][r]);
    while(l<=n){
        rep(i,l,r){
            res[c++]=s[i];
        }
        res[c++]='\n';
        P w=P(r+1,nex[l][r]);
        l=w.fi,r=w.se;
    }
    res[c-1]='\0';
    printf("%s",res);
    return 0;
}