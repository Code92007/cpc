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
const int mod=1e9+7;
int t;//1010
ll n,dp[64][5],sum[64];
ll dfs(int x,bool has,bool lim){
    printf("x:%d has:%d lim:%d sum:%lld\n",x,has,lim,sum[x+1]);
    if(x<0)return has;
	if(!lim)return sum[x+1];
    ll ans=0;
	int up=n>>x&1;
    rep(i,0,up){
        ans+=dfs(x-1,has||i,lim&&(i==up));
    }
    //printf("x:%d w:%d up:%d lim:%1d\n",x,n>>x&3,up,lim);
    //ans+=dfs(x-2,has,lim&&(0==up));//000
    //if(has && 1<=up)ans+=dfs(x-2,1,lim&&(1==up));//321
    //if(3<=up)ans+=dfs(x-2,1,lim&&(3==up));//123
    //for(int i=0;i<)//(0,0,0)(3,2,1)(1,2,3)
	// for(int i=0;i<=up;++i){
    //     for(int j=0;j<=3;++j){
    //         for(int k=0;k<=3;++k){
    //             //if(j==k || i==j || i==k)continue;
    //             if(!(k-j==j-i))continue;
    //             if((i&j)>0 || (i&k)>0 || (j&k)>0)continue;
    //             if(!has && !(k<=j && j<=i))continue;
    //             bool yep=i>0;
    //             printf("x:%d i:%d j:%d k:%d up:%d\n",x,i,j,k,up);
    //             ans+=dfs(x-2,yep,lim && (i==up));
    //         }
    //     }
	// }
	//printf("dp[%d][%d][%1d][%1d]:%lld\n",x,trail,one,lim,dp[x][trail][one][lim]);
	return ans;
}
int main(){
    dp[2]=dp[3]=1;
    sum[2]=1;sum[3]=2;
    rep(i,4,63){
        dp[i]=2ll*sum[i-2]+1;
        sum[i]=sum[i-1]+dp[i];
    }
    sci(t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n",dfs(62,0,1)%mod);
		//memset(dp,-1,sizeof dp);
		//printf("%lld\n",dfs(63,0,0,1))
    }
    //bin(20);
    // rep(i,1,1000){
    //     rep(j,i,1000){
    //         int k=i^j;
    //         if(j-i==k-j){
    //             printf("%d %d %d ",i,j,k);
    //             bin(i),bin(j),bin(k);
    //             puts("");
    //         }
    //     }
    // }
    // sci(t);
    // while(t--){
    // }
    return 0;
}