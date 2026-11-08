//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
int n,u,v,a[N],mx,rt,rt2;
vector<int>e[N];
map<P,int>mp[N];
ll ans;
void dfs(int u,int fa,int d){
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u,d+1);
        if(SZ(mp[v])>SZ(mp[u])){
            swap(mp[v],mp[u]);
        }
        for(auto &x:mp[v]){
            P f=x.fi;
            int cnt=x.se;
            int w=2*d+mx-f.se;
            //printf("(%d,%d) d:%d w:%d\n",f.fi,f.se,d,w);
            if(mp[u].count(P(f.fi,w))){
                ans+=1ll*cnt*mp[u][P(f.fi,w)];
            }
        }
        for(auto &x:mp[v]){
            mp[u][x.fi]+=x.se;
        }
    }
    if(mp[u].count(P(a[u],mx+d))){
        ans+=mp[u][P(a[u],mx+d)];
    }
    mp[u][P(a[u],d)]++;
}
void dfs2(int u,int fa,int d){
    if(d>mx)mx=d,rt=u;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs2(v,u,d+1);
    }
}
int main(){
    sci(n);
    rep(i,2,n){
        sci(u),sci(v);
        e[u].pb(v);
        e[v].pb(u);
    }
    rep(i,1,n){
        sci(a[i]);
    }
    dfs2(1,0,0);
    mx=0;
    dfs2(rt,0,0);
    //printf("mx:%d rt:%d\n",mx,rt);
    dfs(rt,0,0);
    printf("%lld\n",ans);
    return 0;
}