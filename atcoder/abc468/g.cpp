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
const int N=2e3+10,mod=998244353;
int n,fac[N],ans,las=1;
char s[N];
int main(){
    fac[0]=1;
    rep(i,1,2000){
        fac[i]=1ll*fac[i-1]*i%mod;
    }
    sci(n);
    scanf("%s",s+1);
    if(s[1]!='o' || s[n]!='o'){
        puts("0");
        return 0;
    }
    ans=1;
    rep(i,2,n){
        if(s[i]=='o'){
            int x=i-las;
            //printf("x:%d\n",x);
            int w=(fac[x]-fac[x-1]+mod)%mod;
            ans=2ll*ans%mod*w%mod;
        }
    }
    pte(ans);
    return 0;
}