//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=2e5+10;
int t,n,u,v,ans[N];
vector<int>e[N];
void dfs(int u,int fa){
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        ans[u]+=SZ(e[v])-1;
    }
    if(fa)ans[u]+=SZ(e[fa])-1;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n)e[i].clear(),ans[i]=0;
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(1,0);
        int res=ans[1],pos=1;
        rep(i,2,n){
            if(ans[i]>res)res=ans[i],pos=i;
        }
        printf("%d %d\n",pos,ans[pos]);
    }
    return 0;
}
