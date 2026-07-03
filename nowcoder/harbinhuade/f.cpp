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
typedef pair<ll,int> P;
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
const int N=1e5+10;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,m,u,v,w,s,x,t;
ll dis[N];
bool vis[N];
vector<P>e[N];
priority_queue<P>q;
ll dij(int s,int t){
    memset(dis,INF,sizeof dis);
    dis[s]=0;
    memset(vis,0,sizeof vis);
    while(!q.empty())q.pop();
    q.push(P(0,s));
    while(!q.empty()){
        P x=q.top();q.pop();
        //printf("x.fi:%lld x.se:%d dis:%lld\n",x.fi,x.se,dis[x.se]);
        if(vis[x.se])continue;
        vis[x.se]=1;
        for(auto &y:e[x.se]){
            //printf("y.fi:%lld y.se:%d\n",y.fi,y.se);
            int p=y.fi;
            if(dis[p]>dis[x.se]+y.se){
                //printf("y.fi:%lld dis:%lld\n",y.fi,dis[y.fi]);
                dis[p]=dis[x.se]+y.se;
                q.push(P(-dis[p],y.fi));
            }
        }
    }
    return dis[t];
}
int main(){
    sci(n),sci(m);
    rep(i,1,m){
        sci(u),sci(v),sci(w);
        e[u].pb(P(v,w));
        e[v].pb(P(u,w));
    }
    sci(s),sci(x),sci(t);
    ll dis1=dij(s,x);
    ll dis2=dij(x,t);
    printf("%lld\n",dis1+dis2);
    return 0;
}