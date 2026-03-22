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
const int N=5e5+10,mod=1e9+7;
//x次代价n+x-1，最小化操作次数
int t,n,pre[N];
char s[N];
int cal(int l,int r){
    return pre[r]-pre[l-1];
}
int sol(){
    rep(i,1,n){
        int v=(s[i]=='1'?1:-1);
        pre[i]=pre[i-1]+v;
    }
    if(pre[n]==-n)return -n;//全0
    if(pre[n]>=0){
        if(n==1)return 0;//1
        return 1;//1>=0
    }
    if(s[1]=='1' || s[n]=='1' || pre[n]==-1)return 2;
    int ans=4;
    if(pre[n]==-2)ans=3;
    //有一个前缀/后缀1>=0，就可以先消它，得到一个前缀1或一个后缀1，3次
    rep(i,1,n){
        //先消前缀/后缀得到一个数，这后消全部，这个时候一定有一个前缀/后缀>0，2次
        int p=cal(1,i),q=cal(i,n);
        //printf("i:%d p:%d q:%d\n",i,p,q);
        if(p>0)ans=2;
        else if(p==0){
            if(i==n-1)ans=2;
            else ans=min(ans,3);
        }
        if(q>0)ans=2;
        else if(q==0){
            if(i==2)ans=2;
            else ans=min(ans,3);
        }
    }
    //0000110000这种也是ans=3，消一个[1,i]消一个[j,n]然后[i+1,j-1]的1的个数最大，这要求最大子段和>=2
    vector<int>dp(n+1,0);
    int mx=0;
    rep(i,1,n){
        int v=(s[i]=='1'?1:-1);
        dp[i]=max(0,dp[i-1])+v;
        mx=max(mx,dp[i]);
    }
    if(mx>=2)ans=min(ans,3);
    return ans;
    //最坏情况00000001000000，ans=4
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        printf("%d\n",n+sol()-1);
    }
    return 0;
}