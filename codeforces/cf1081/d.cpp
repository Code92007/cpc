//草 又看错题了
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
typedef pair<int,int> P;
typedef array<int,3> A;
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
int t,n,a[N],u,v,mx[N];
ll dp[N],sum[N],add[N];
vector<int>e[N];
void dfs(int u,int fa){
    sum[u]=a[u];
    dp[u]=0;
    int p=u,mx2=0;
    mx[u]=0;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        dp[u]+=dp[v]+sum[v];
        sum[u]+=sum[v];
        if(mx[u]<mx[v]+1){
            mx2=mx[u];
            mx[u]=mx[v]+1;
            p=v;
        }
        else if(mx2<=mx[v]+1){
            mx2=mx[v]+1;
        }
        add[u]=max(add[u],add[v]);
    }
    for(auto &v:e[u]){
        if(v==fa)continue;
        int mul=(v==p?mx2:mx[u]);
        add[u]=max(add[u],sum[v]*mul);
    }
}
int main() {
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
            e[i].clear();
            add[i]=0;
        }
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(1,0);
        rep(i,1,n){
            printf("%lld%c",dp[i]+add[i]," \n"[i==n]);
        }
    }
    return 0;
}