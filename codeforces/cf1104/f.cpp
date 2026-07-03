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
const int N=5e5+10,INF=0x3f3f3f3f;
int t,n,m,a[N],dp[N],tmp[N],mx[N],tag[N];
/*
接下来考虑用动态规划从左到右计算答案。等价地，我们要最大化不需要修改的位置数量。设 dp_i 表示最后一个未修改位置为 i 时，最多可以保留多少个未修改位置。
如果位置 i 的 DP 值可以转移到位置 j（其中 i < j），则以下三个条件之一必须成立：
1. a_j - a_i = j - i，表示位置 i 和 j 在同一次涂色操作中。 下标j-a[j]
2. m - a_i < j - i，表示 j 位于包含位置 i 的涂色段的右边界之外。 i对[i+m-a[i]+1,n]后缀有作用 打个tag
3. a_j - 1 < j - i，表示 i 位于包含位置 j 的涂色段的左边界之外。 [1,j-a[j]]前缀i可以取 求个前缀mx
suf<=n表示这个点不改之后 这一段的结尾m还能落在位置n及之前 使答案合法
*/
int sol(){
    int add=-INF;
    rep(i,1,n){
        add=max(add,tag[i]);
        int p=i-a[i],suf=i+m-a[i];
        if(suf<=n){
            if(p>=0)dp[i]=max(dp[i],tmp[p]+1);
            dp[i]=max(dp[i],add+1);
            int pre=i-a[i];
            if(pre>=1)dp[i]=max(dp[i],mx[pre]+1);
        }
        int nex=i+m-a[i]+1;
        if(nex<=n)tag[nex]=max(tag[nex],dp[i]);
        mx[i]=max(mx[i-1],dp[i]);
        if(p>=0)tmp[p]=max(tmp[p],dp[i]);
    }
    return n-mx[n];
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        tmp[0]=0;
        rep(i,1,n){
            sci(a[i]);
            dp[i]=mx[i]=-INF;
            tmp[i]=tag[i]=-INF;
        }
        pte(sol());
    }
    return 0;
}