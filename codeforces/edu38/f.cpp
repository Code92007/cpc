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
using namespace std;
const int N=5e3+10;
int n,m,x;
char s[N];
bool dp[N];
int main(){
    scanf("%s",s);
    n=strlen(s);
    m=1,x=0;
    while(m*2<=n)m*=2,x++;
    dp[0]=1;
    rep(i,0,n-m){
        rep(j,0,m-1){
            if(!dp[j])continue;
            rep(k,0,x-1){
                if(!(j>>k&1)){
                    dp[j|(1<<k)]|=dp[j];
                }
            }
        }
        char mn='z';
        rep(j,0,m-1){
            if(!dp[j])continue;
            if(s[i+j]<mn)mn=s[i+j];
        }
        putchar(mn);
        rep(j,0,m-1){
            if(s[i+j]==mn && dp[j])dp[j]=1;
            else dp[j]=0;
        }
    }
    return 0;
}