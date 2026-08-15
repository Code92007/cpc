//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=1e5+10,M=2e6+10,K=1e4;
int n,q,u,v,a[N],to[M],w[N],c,ans[N];
ll sum,now,ori;
bool vis[M];
vector<P>e[N];
vector<int>l,r;
void dfs(int u,int fa){
    for(auto &x:e[u]){
        int v=x.fi,id=x.se;
        if(v==fa)continue;
        w[v]=r[c];
        to[r[c]]=v;
        c++;
        ans[id]=w[v]-w[u];
        sum+=1ll*a[v]*w[v];
        dfs(v,u);
    }
}
int main(){
    sci(n),sci(q);
    rep(i,1,n)sci(a[i]);
    for(int i=2;i<M;++i){
        if(!vis[i]){
            if(i>K)r.pb(i);
            else l.pb(i);
        }
        for(int j=2*i;j<M;j+=i){
            vis[j]=1;
        }
    }
    rep(i,1,n-1){
        sci(u),sci(v);
        e[u].pb(P(v,i));
        e[v].pb(P(u,i));
    }
    dfs(1,0);
    rep(i,1,n-1){
        printf("%d\n",ans[i]);
    }
    fflush(stdout);
    while(q--){
        printf("? %d\n",1);
        fflush(stdout);
        scanf("%lld",&now);
        int sg=1;
        if(now<sum)sg=-1;
        now=abs(now-sum),ori=now;
        for(auto &v:l){
            while(now%v==0)now/=v;
        }
        int id=to[now];
        printf("! %d %d\n",id,a[id]+(ori/w[id])*sg);
        fflush(stdout);
    }
    return 0;
}