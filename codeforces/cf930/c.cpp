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
const int N=4e5+10,M=8e5+10;
const ll INF=4e18;
int t,n,m,c[N];
bool vis[M];
vector<P>e[M];
ll dis[M];
priority_queue<P,vector<P>,greater<P>>q;
void add(int x,int y,int w){
    e[x].pb(P(y,w));
}
int f(int x,int y){
    x--,y--;
    return x*m+y;
}
int s(int i){
    return n*m+i;
}
void dij(int u){
    while(!q.empty())q.pop();
    q.push(P(0,u));
    dis[u]=0;
    while(!q.empty()){
        P x=q.top();
        q.pop();
        u=x.se;
        if(vis[u])continue;
        vis[u]=1;
        //printf("u:%d dis:%lld\n",u,dis[u]);
        for(auto &y:e[u]){
            int v=y.fi,w=y.se;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push(P(dis[v],v));
            }
        }
    }
}
void sol(){
    sci(n),sci(m);
    rep(i,1,n)sci(c[i]);
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    rep(i,1,n){
        rep(j,1,m){
            sci(a[i][j]);
        }
    }
    int up=n*m+n;
    rep(i,0,up){
        e[i].clear();
        dis[i]=INF;
        vis[i]=0;
    }
    rep(i,1,n){
        rep(j,1,m){
            add(s(i),f(i,j),0);
            add(f(i,j),s(i),c[i]);
        }
    }
    rep(j,1,m){
        vector<P>z;
        rep(i,1,n){
            z.pb(P(a[i][j],i));
        }
        sort(z.begin(),z.end());
        rep(i,0,n-2){
            P x=z[i],y=z[i+1];
            add(f(x.se,j),f(y.se,j),0);
            add(f(y.se,j),f(x.se,j),y.fi-x.fi);
        }
    }
    dij(s(1));
    printf("%lld\n",dis[s(n)]);
}
int main(){
    sci(t);
    while(t--){
        sol();
    }
    return 0;
}