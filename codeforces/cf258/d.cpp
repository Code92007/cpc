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
//思路:注意到只有ab两种字符，所以只可能是形如01010或者10101
const int N=1e5+10;
int n;
char s[N];
ll dp[2],seg[2];
//dpi表示奇数段/偶数段的方案，seg[i]表示压缩后是奇数还是偶数的方案 只有压缩后是奇数的才是回文串
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    seg[0]=1;
    for(int i=1;i<=n;++i){
        if(i==1 || s[i]!=s[i-1]){
            dp[0]+=
        }
    }
    return 0;
}