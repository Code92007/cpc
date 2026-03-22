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
const int N=1e5+10,mod=123456789;
int n,v,two[N];
map<int,int>mp;
int main(){
    sci(n);
    two[0]=1;
    rep(i,1,n){
        two[i]=2ll*two[i-1]%mod;
        sci(v);
        mp[v]++;
    }
    int las=-1,res=0,ans=1;
    for(auto &v:mp){
        if(v.fi!=las+1)break;
        if(v.fi==0){
            if(v.se!=n)res++;
        }
        else{
            res=(res+ans)%mod;
        }
        ans=1ll*ans*(two[v.se]-1)%mod;
        las=v.fi;
    }
    pte(res);
    return 0;
}
/*
1 2 4 2^2-1
1 2 4 8 2^3-1
1 2 4
3 7
6   x
*/