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
const int N=2e5+10,mod=998244353;
int modpow(int x,int n,int mod){
    if(n==-1)n=mod-2;//n^(k-2) n^(k-3)
    int res=1;
    for(;n;n/=2,x=1ll*x*x%mod){
        if(n&1)res=1ll*res*x%mod;
    }
    return res;
}
int t,n,m,u,v,par[N],sz[N],up[N],ans[N],son[N];
vector<int>e[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
void mer(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return;
    par[v]=u;
    sz[u]+=sz[v];
}
void dfs(int u,int fa){
    up[u]=fa;
    son[u]=1;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        son[u]+=son[v];
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,n){
            e[i].clear();
            par[i]=i;
            sz[i]=1;
            ans[i]=0;
            son[i]=0;
            up[i]=0;
        }
        rep(i,1,m){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
            mer(u,v);
        }
        dfs(n,0);
        int k=0,prod=1;
        rep(i,1,n){
            if(find(i)==i){
                k++;
                prod=1ll*prod*sz[i]%mod;
            }
        }
        if(find(n)==find(n-1)){
            int u=n-1;
            while(up[u]!=n){
                u=up[u];
            }
            //printf("k:%d prod:%d\n",k,prod);
            ans[u]=1ll*modpow(n,k-2,mod)*prod%mod;
            //else ans[u]=1;
        }
        else{
            int fn=find(n);
            rep(i,1,n-1){
                int fa=find(i);
                if(fa==fn){
                    int prob=1ll*son[i]*modpow(son[n],mod-2,mod)%mod;
                    if(up[i]==n)ans[i]=1ll*modpow(n,k-2,mod)*prod%mod*prob%mod;
                    else ans[i]=0;
                }
                else{
                    int prob=1ll*sz[fa]*modpow(sz[fa]+sz[fn],mod-2,mod)%mod;
                    int prod2=1ll*prod*modpow(sz[fa],mod-2,mod)%mod*modpow(sz[fn],mod-2,mod)%mod*(sz[fa]+sz[fn])%mod;
                    ans[i]=1ll*modpow(n,k-3,mod)*prod2%mod;
                    if(find(n-1)!=fa)ans[i]=1ll*ans[i]*prob%mod;
                }
            }
        }
        rep(i,1,n-1){
            printf("%d%c",ans[i]," \n"[i==n-1]);
        }
    }
    return 0;
}