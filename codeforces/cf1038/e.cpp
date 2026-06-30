//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,int> P;
typedef array<int,3> A;
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
const int N=505,M=505,mod=998244353;
//dp[i][j]表示考虑[i,n-1]列时，历史最大前缀和为j时的方案数
//每一项是a[0][i+1]-a[1][i]，记为b[i]
//要求:如果某一项b[i]<0，则从b[i]开始往后的前缀和不能大于0
//从i往前的位置的约束，不如从i这一项的约束更严格，所以只考虑单项的约束
int t,n,k,a[2][N],dp[N][M];
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        rep(i,0,1){
            rep(j,1,n){
                sci(a[i][j]);
            }
        }
        rep(i,1,n){
            rep(j,0,k){
                dp[i][j]=0;
            }
        }
        dp[n][0]=1;
        per(i,n-1,1){
            rep(j,0,k){
                if(!dp[i+1][j])continue;
                int maxDelta=k-1;
                rep(z,-maxDelta,maxDelta){
                    if(z<0 && z+j>0)continue;//出现第一个小于0后，加历史最大后缀后>0，不合法
                    int x=a[0][i+1],y=a[1][i],w=0;//x-y=z
                    if(x==-1 && y==-1)w=k-abs(z);//差为z的方式有k-abs(z)种，差为0有k种，差为1有k-1种，下同
                    else if(x==-1)w=(1<=y+z && y+z<=k);//x-y=z,x=y+z∈[1,k]
                    else if(y==-1)w=(1<=x-z && x-z<=k);//x-y=z,y=x-z∈[1,k]
                    else w=(x-y==z);
                    //由于maxDelta只有[1-k,k-1]，所以历史最大后缀>=k的都认为是等于k即可，因为maxDelta<0一定不合法，所以等于k的后续转移里只能有z>=0的项
                    //历史最大和如果小于0，可以认为不取这个后缀，使前缀和取到0，倒着dp是因为新加入一个值，可以影响所有后缀，无后效性，也就影响了历史最大后缀
                    int nj=max(0,min(z+j,k));
                    add(dp[i][nj],1ll*w*dp[i+1][j]%mod);
                }
            }
        }
        int ans=0;
        rep(i,0,k){
            add(ans,dp[1][i]);
        }
        if(a[0][1]==-1)ans=1ll*ans*k%mod;
        if(a[1][n]==-1)ans=1ll*ans*k%mod;
        pte(ans);
    }
    return 0;
}