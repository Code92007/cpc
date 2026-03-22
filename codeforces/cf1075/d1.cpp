#include<bits/stdc++.h>
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
const int N=2e5+10,mod=1e9+7;
int t,n,c;//fac[N];
char s[N];
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int sol(){
    if(s[1]=='0' || s[n]=='0'){
        return -1;
    }
    int ans=1,v;
    rep(i,1,n-1){
        if(s[i]=='1')v=2;
        else if(s[i]=='0')v=i-1;
        else{
            if(i%2==0)v=2,s[i]='1';
        }
        int g=gcd(c,v);
        c/=g;
        ans=1ll*ans*v%mod;
    }
    if(c==1)return -1;
    int d=c;
    while(d%2==0)d/=2;
    if(d==1){
        per(i,n-1,1){
            if(s[i]!='?')continue;
            if(c/2>1)ans=2ll*ans%mod,c/=2;
            else ans=1ll*ans*(i-1)%mod;
        }
    }
    else{
        per(i,n-1,1){
            if(s[i]!='?')continue;
            ans=2ll*ans%mod;
        }
    }
    return c==1?-1:ans;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(c);
        scanf("%s",s+1);
        printf("%d\n",sol());
    }
    return 0;
}