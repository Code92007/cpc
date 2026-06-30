//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
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
using namespace std;
const int N=2e3+10,mod=1e9+7;
int n,s,t,dp[N][N];//dp[i][j]表示从小到大前i个数分成j个Λ波动序列的方案数
//这j个序列是有序的，也就是在最终序列里第一段严格在第二段前面，并且至多只有最左和最右可能是v，其他段都是Λ，这样才能在两个Λ之间插入一个数使合并序列仍为ΛΛΛ波浪序列
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    scanf("%d%d%d",&n,&s,&t);
    dp[1][1]=1;
    rep(i,1,n-1){
        rep(j,1,i){
            int v=i+1;
            if(v==s || v==t){
                add(dp[i+1][j],dp[i][j]);//不新增段，只能续在第一段开头或最后一段结尾
                add(dp[i+1][j+1],dp[i][j]);//新增一段，也只能在第一段前或最后一段后
            }
            else{
                int val=(v<s)+(v<t);
                if(j>=2)add(dp[i+1][j-1],1ll*(j-1)*dp[i][j]%mod);//合并，减少一段，可以在j段的j-1个空之间使相邻两段合并
                add(dp[i+1][j+1],1ll*(j-1+val)*dp[i][j]%mod);//新增一段，可以在没出现s前在第一段前开一段，或没出现t前在最后一段后开一段，或在j段之间的j-1个空新开一段
            }
        }
    }
    printf("%d\n",dp[n][1]);//n个数，合成一段的方案数
    return 0;
}