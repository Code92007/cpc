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
typedef pair<int,int> P;
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
int n,k,u,v,Finv[N],fac[N],inv[N],sz[N],ans;
vector<int>e[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
int modpow(int x,int n,int mod){
	int res=1;
	for(;n;x=1ll*x*x%mod,n>>=1)
	if(n&1)res=1ll*res*x%mod;
	return res;
}
void init(int n){ //n<N
    inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=Finv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod,Finv[i]=1ll*Finv[i-1]*inv[i]%mod;
	//Finv[n]=modpow(fac[n],mod-2,mod);
	//for(int i=n-1;i>=1;--i)Finv[i]=1ll*Finv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	if(m<0||m>n)return 0;
	return 1ll*fac[n]*Finv[n-m]%mod*Finv[m]%mod;
}
void dfs(int u,int fa){
    sz[u]=1;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        sz[u]+=sz[v];   
    }
    add(ans,1ll*C(sz[u],k/2)*C(n-sz[u],k/2)%mod);
}
int sol(){
    if(k&1)return 1;
    dfs(1,0);
    int inv=modpow(C(n,k),mod-2,mod);
    ans=1ll*ans*inv%mod;
    ans=(ans+1)%mod;
    return ans;
}
int main(){
    init(N-5);
    sci(n),sci(k);
    rep(i,2,n){
        sci(u),sci(v);
        e[u].pb(v);
        e[v].pb(u);
    }
    printf("%d\n",sol());
	return 0;
}