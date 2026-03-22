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
const int N=2e5+10;
int t,n,m,u,v,dp[N],mx[N],sz[N];
vector<int>e[N];
struct Bit{
	int n;
    ll tr[N];
	void init(int _n){
		n=_n;
		memset(tr,0,(n+1)*sizeof(*tr));
	}
	void add(int x,int v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]+=v;
	}
	ll sum(int x){
		ll ans=0; 
		for(int i=x;i;i-=i&-i)
		ans+=tr[i];
		return ans;
	}
}tr1,tr2;
void dfs(int u){
    sz[u]=1;
    for(auto &v:e[u]){
        dfs(v);
        if(sz[v]>sz[u])
        sz[u]+=sz[v];
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);sci(m);
        tr1.init(n);
        tr2.init(n);
        rep(i,1,n){
            e[i].clear();
        }
        rep(i,1,n-1){
            mx[i]=i+1;
        }
        rep(i,1,m){
            sci(u),sci(v);
            mx[u]=max(mx[u],v);
        }
        rep(i,1,n-1){
            e[mx[u]].pb(u);
        }
        dfs(n);
    }
    return 0;
}