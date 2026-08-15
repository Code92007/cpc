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
const int N=2e6+10,INF=0x3f3f3f3f,K=3;
int t,n,x,y,sz,dp[1400],mn[K+1];
vector<int>tmp;
map<int,int>mp;
int main(){
    sci(t);
    while(t--){
        sci(n);
        if(mp.count(n)){
            printf("%d\n",mp[n]);
            continue;
        }
        int w=n+1;
        tmp.clear();
        rep(i,1,32000){
            if(1ll*i*i>w)break;
            if(w%i==0){
                tmp.pb(i);
                if(w/i!=i)tmp.pb(w/i);
            }
        }
        sort(tmp.begin(),tmp.end());
        memset(dp,INF,sizeof dp);
        int m=tmp.size();
        dp[0]=0;
        rep(i,0,K)mn[i]=-1;
        mn[0]=0;
        rep(i,1,m-1){
            int w=tmp[i];
            rep(x,0,K){
                if(mn[x]==-1)continue;
                int j=mn[x],v=tmp[j];
                dp[i]=min(dp[i],dp[j]+(w-1)/v);
            }
            rep(x,0,K){
                if(mn[x]==-1)continue;
                int j=mn[x],v=tmp[j];
                if(dp[j]>=dp[i] || dp[j]+(w-1)/v>dp[i]+2){
                    mn[x]=-1;
                }
            }
            rep(x,0,K){
                if(mn[x]==-1){
                    mn[x]=i;
                    break;
                }
            }
            //printf("i:%d v:%d dp:%d\n",i,tmp[i],dp[i]);
            // per(j,i-1,0){
            //     int v=tmp[j];
            //     //if(dp[j]<dp[i-1]-2)break;
            // }
        }
        sz=SZ(tmp);
        //for(auto &v:tmp)printf("%d ",v);puts("");
        printf("%d\n",mp[n]=dp[m-1]);
    }
    return 0;
}