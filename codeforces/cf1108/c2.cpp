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
const int N=2e5+10,mod=1e9+7;
int t,n,v;
map<int,int>cnt;
int modpow(int x,int n,int mod){
	int res=1;
	for(;n;x=1ll*x*x%mod,n>>=1)
	if(n&1)res=1ll*res*x%mod;
	return res;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        cnt.clear();
        rep(i,1,n){
            sci(v);
            cnt[v]++;
        }
        int zero=1,tot=1;
        bool ok=0;
        for(auto &x:cnt){
            ok|=(x.fi==-1);
            zero=1ll*zero*modpow(2,x.se-1,mod)%mod;
            tot+=cnt.count(x.fi+1);
        }
        if(ok)zero=1ll*zero*tot%mod;
        pte(zero);
    }
    return 0;
}