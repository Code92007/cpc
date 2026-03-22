//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;
#define ull unsigned long long
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
int n,m,v,a[N],sz[N],cnt[N],par[N],hold[N],las[N],ans[3];
char s[5];
set<int>e[N];
void dfs(int u,int anc){
    //tmp.pb(u);
    //vis[u]=1;
    //printf("u:%d anc:%d\n",u,anc);
    sz[u]=1;
    par[u]=anc;
    for(auto &v:e[u]){
        if(hold[v])continue;
        dfs(v,anc);
        sz[u]+=sz[v];
    }
}
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        if(i!=a[i]){
            e[a[i]].insert(i);
        }
    }
    sci(m);
    while(m--){
        scanf("%d%s",&v,s);
        int p;
        if(s[0]=='C')p=0;
        else if(s[0]=='O')p=1;
        else p=2;
        hold[v]++;
        if(hold[v]==1){
            if(v!=a[v])e[a[v]].erase(v);
            //e[a[v]].clear();
            dfs(v,v);
            //printf("fa:%d\n",fa);
            if(fa){
                ans[las[fa]]-=cnt[v];
                cnt[fa]-=cnt[v];
            }
            ans[p]+=cnt[v];
        }
        else{
            ans[las[v]]-=cnt[v];
            ans[p]+=cnt[v];
        }
        las[v]=p;
        rep(i,0,2){
            printf("%d%c",ans[i]," \n"[i==2]);
        }
    }
    return 0;
}