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
int t,n,u,v,par[N];
vector<int>e[N],ans;
void dfs(int u,int fa){
    par[u]=fa;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
}
void out(){
    printf("%d\n",SZ(ans));
    for(auto &v:ans){
        if(v==-1)printf("%d\n",1);
        else printf("%d %d\n",2,v);
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            e[i].clear();
        }
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(n,0);
        ans.clear();
        for(int i=1;i!=n;i=par[i]){
            for(auto &v:e[i]){
                if(v==par[i])continue;
                ans.pb(v);
            }
            ans.pb(-1);
        }
        out();
    }
    return 0;
}