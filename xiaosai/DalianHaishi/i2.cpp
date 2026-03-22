//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
#include<unordered_map>
#include<set>
#define ll long long
#define ull unsigned ll
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef double db;
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
using namespace std;
typedef pair<int,int> P;
const int N=1e6+10;
int n,m,q,x[N],y[N],op[N],ans[N],u[N],v[N],sz[N];
int par[N],seg;
bool del[N];
vector<int>e[N],f[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
void mer(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return;
    if(sz[u]<sz[v])swap(u,v);
    par[v]=u;
    sz[u]+=sz[v];
    seg--;
}
int main(){
    sci(n),sci(m),sci(q);
    rep(i,1,n)par[i]=i,sz[i]=1;
    seg=n;
    rep(i,1,m){
        sci(u[i]),sci(v[i]);
        if(u[i]>v[i])swap(u[i],v[i]);
        e[u[i]].pb(v[i]);
    }
    rep(i,1,q){
        sci(op[i]);
        if(op[i]==3)continue;
        sci(x[i]),sci(y[i]);
        if(x[i]>y[i])swap(x[i],y[i]);
        if(op[i]==1){
            f[x[i]].pb(y[i]);
        }
    }
    rep(i,1,n){
        for(auto &v:f[i]){
            del[v]=1;
        }
        for(auto &v:e[i]){
            if(del[v])continue;
            mer(i,v);
        }
        for(auto &v:f[i]){
            del[v]=0;
        }
    }
    per(i,q,1){
        if(op[i]==3){
            ans[i]=seg-1;
        }
        else if(op[i]==2){
            if(find(x[i])==find(y[i]))ans[i]=1;
            else ans[i]=0;
        }
        else{
            mer(x[i],y[i]);
        }
    }
    rep(i,1,q){
        if(op[i]==1)continue;
        if(op[i]==3)printf("%d\n",ans[i]);
        else printf("%s\n",ans[i]==1?"YES":"NO");
    }
    return 0;
}
/*
1 3 5 7 9 11 1023 1 = 512*1
2 256*2
4 
8
16
32
64
128
256
512
512*1
256*2

*/