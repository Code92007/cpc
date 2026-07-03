#include<bits/stdc++.h>
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
typedef pair<int,int> P;
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
const int N=1e5+10,M=2e5+10;
int t,n,m,u,v,w,mx;
int par[N],cnt[2],sz[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
struct edge{
    int u,v,w;
    void read(){sci(u),sci(v),sci(w);}
}e[M];
bool cmp1(edge a,edge b){
    return a.w<b.w;
}
bool mer(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return 0;
    par[v]=u;
    sz[u]+=sz[v];
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,m){
            e[i].read();
        }
        ll ans=0;
        cnt[0]=cnt[1]=0;
        sort(e+1,e+m+1,cmp1);
        mx=0;
        rep(i,1,n)par[i]=i,sz[i]=1;
        rep(i,1,m){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(mer(u,v))cnt[w]++;
        }
        if(sz[find(1)]<n){
            puts("0");
            continue;
        }
        //printf("cnt0:%d cnt1:%d\n",cnt[0],cnt[1]);
        //rep(i,1,n)mx=max(mx,sz[i]);
        mx=cnt[0];
        cnt[0]=cnt[1]=0;
        //sort(e+1,e+m+1,cmp2);
        //mx=0;
        rep(i,1,n)par[i]=i,sz[i]=1;
        per(i,m,1){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(mer(u,v))cnt[w]++;
        }
        //rep(i,1,n)mx=max(mx,sz[i]);
        //printf("cnt0:%d cnt1:%d\n",cnt[0],cnt[1]);
        pte(mx-cnt[0]+1);
    }
    return 0;
}
/*
ba ab

cdaba dcaba
cdabba dc
cd abbadc
*/