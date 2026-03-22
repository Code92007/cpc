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
typedef pair<ll,ll> P;
typedef array<ll,3> A;
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
const int N=3e5+10,M=2*N,mod=998244353;
//首先[l,r]不能是同一种数字
//那么dp[i]表示钦定i和i-1不同且满足每个前缀的区间限制时的方案数
int t,n,m,l,r,dp[N],sum[N],mx[N];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,n+1){
            mx[i]=0;
            dp[i]=0;
            sum[i]=0;
        }
        rep(i,1,m){
            sci(l),sci(r);
            mx[r]=max(mx[r],l+1);//[j,i-1]完全相同，[j,i-1]完全包含[l,r]是不行的，所以需要满足j>l
        }
        dp[1]=sum[1]=1;
        int now=1;//上一个翻面的位置位于[now,i-1]最后都可以，本次落于i
        rep(i,2,n+1){
            dp[i]=(sum[i-1]-sum[now-1])%mod;
            dp[i]=(dp[i]+mod)%mod;
            sum[i]=(sum[i-1]+dp[i])%mod;
            //printf("i:%d now:%d dp:%d\n",i,now,dp[i]);
            now=max(now,mx[i]);
        }
        printf("%lld\n",2ll*dp[n+1]%mod);
    }
    return 0;
}