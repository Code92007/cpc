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
int t;
ll n,dp[64];
// void bin(int x){
//     string y="";
//     for(;x;x/=2)y+=(x%2)+'0';
//     reverse(y.begin(),y.end());
//     cout<<y<<" ";
//     //puts("");
// }

ll n,m,dp[64][65][2][2];
ll dfs(int x,int trail,bool one,bool lim){
	if(x==-1){
		return one==1 && !lim;
	}
	if(~dp[x][trail][one][lim])return dp[x][trail][one][lim];
	ll &ans=dp[x][trail][one][lim];ans=0;
	int bit=n>>x&1,up=lim?(m>>x&1):1;
	for(int i=0;i<=up;++i){
		int w=bit+i;
		if(!w)ans+=dfs(x-1,0,one,lim && (i==up));
		else if(w==1)ans+=dfs(x-1,trail+1,one^1^i,lim && (i==up));
		else if(w==2)ans+=dfs(x-1,0,one^((trail-1)&1)^1,lim && (i==up));
	}
	//printf("dp[%d][%d][%1d][%1d]:%lld\n",x,trail,one,lim,dp[x][trail][one][lim]);
	return ans;
}
int main(){
    sci(t);
    while(t--){
        scanf("%lld",&n);
		memset(dp,-1,sizeof dp);
		printf("%lld\n",dfs(63,0,0,1))
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