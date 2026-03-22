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
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" "
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
const int N=2e5+10,M=19;
const ll INF=-2e14;
vector<int>e[N];
int n,q,u,v,a[N],b[N],c[N],par[N][M],dep[N];
struct node{
    ll a,b,c;
    ll ab,ba,ac,bc,bac,abc;
    ll cb,ca,cab,cba;
    node(){
        a=b=ab=ba=bac=abc=cab=cba=ac=ca=cb=bc=INF;
        c=0;
    }
    node(int x,int y,int z):a(x),b(y),c(z){
        ab=ba=bac=abc=cab=cba=INF;
        ac=ca=a,cb=bc=b;
    }
    void out(){
        dbg(a),dbg(b),dbg(c),dbg(ab),dbg(ba),dbg(ba),dbg(ac),dbg(bc),dbg(bac),dbg(abc),dbg(cb),dbg(ca),dbg(cab),dbg2(cba);
    }
}dp[N][M];
node operator+(node x,node y){
    node z;
    z.a=max(x.a,y.a);
    z.b=max(x.b,y.b);
    z.c=max(max(x.c,y.c),x.c+y.c);
    //printf("x.c:%lld y.c:%lld z.c:%lld\n",x.c,y.c,z.c);
    z.ab=max(max(x.ab,y.ab),x.a+y.b);
    z.ba=max(max(x.ba,y.ba),x.b+y.a);
    z.ac=max(max(x.ac+y.c,y.ac),x.a+y.c);
    z.bc=max(max(x.bc+y.c,y.bc),x.b+y.c);
    z.bac=max(max(x.bac+y.c,y.bac),max(x.ba+y.c,x.b+y.ac));
    z.abc=max(max(x.abc+y.c,y.abc),max(x.ab+y.c,x.a+y.bc));
    z.cb=max(max(x.cb,x.c+y.cb),x.c+y.b);
    z.ca=max(max(x.ca,x.c+y.ca),x.c+y.a);
    z.cab=max(max(x.cab,x.c+y.cab),max(x.c+y.ab,x.ca+y.b));
    z.cba=max(max(x.cba,x.c+y.cba),max(x.c+y.ba,x.cb+y.a));
    //z.out();
    return z;
}
ll cal(node x,node y,ll k){
    //原来的剑
    ll ans=k+max(0ll,x.c)+max(0ll,y.c);
    //换剑
    ans=max(ans,x.a+y.cb);//1+2
    ans=max(ans,x.b+y.ca);//1+2
    ans=max(ans,x.ab+y.c);//2+1
    ans=max(ans,x.ba+y.c);//2+1
    ans=max(ans,x.abc+y.c);//3+0
    ans=max(ans,x.bac+y.c);//3+0
    ans=max(ans,y.cba);//0+3
    ans=max(ans,y.cab);//0+3
    return ans;
}
ll cal2(int x,int y,ll k){
    bool swp=0;
    if(dep[x]<dep[y])swap(x,y),swp=1;
    int z=dep[x]-dep[y];
    node ans;
    for(int i=M-1;i>=0;--i){
        if(z>>i&1){
            ans=ans+dp[x][i];
            x=par[x][i];
            //ans.out();
        }
    }
    if(x==y){
        ans=ans+dp[x][0];
        //printf("x:%d y:%d k:%lld swp:%1d\n",x,y,k,swp);
        //ans.out();
        node emp=node();
        if(swp)swap(ans,emp);
        return cal(ans,emp,k);
    }
    //printf("x:%d y:%d k:%lld swp:%1d\n",x,y,k,swp);
    node ans2;
    for(int i=M-1;i>=0;--i){
        if(par[x][i]!=par[y][i]){
            ans=ans+dp[x][i];
            x=par[x][i];
            ans2=ans2+dp[y][i];
            y=par[y][i];
        }
    }
    ans=ans+dp[x][0];
    x=par[x][0];
    ans=ans+dp[x][0];
    ans2=ans2+dp[y][0];
    //printf("lca:%d\n",x);
    if(swp)swap(ans,ans2);
    return cal(ans,ans2,k);
}
void dfs(int u,int fa,int d){
    dep[u]=d;
    par[u][0]=fa;
    rep(i,1,M-1){
        int g=par[u][i-1];
        par[u][i]=par[g][i-1];
        dp[u][i]=dp[u][i-1]+dp[g][i-1];
    }
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u,d+1);
    }
}
int main(){
    sci(n),sci(q);
    rep(i,1,n)sci(a[i]);
    rep(i,1,n)sci(b[i]);
    rep(i,1,n){
        sci(c[i]);
        dp[i][0]=node(a[i],b[i],c[i]);
    }
    rep(i,2,n){
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1,0,0);
    while(q--){
        int k;
        scanf("%d%d%d",&u,&v,&k);
        printf("%lld\n",cal2(u,v,k));
    }
    return 0;
}
/*
3 5 10
a:11 6 10 12
b:1  9 10 13
c:2 10 13 11
*/