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
const int N=2e5+10;
int t,n,u,v,x[N],par[N],dep[N],unknow[N];
ll w,y[N],ans[N],now[N],res;
vector<int>e[N],in[N],edge[N];
void dfs(int u,int fa,int d){
    dep[u]=d;
    par[u]=fa;
    for(auto &v:e[u]){
        dfs(v,u,d+1);
    }
}
int main(){
    sci(t);
    while(t--){
        scanf("%d%lld",&n,&w);
        rep(i,1,n){
            unknow[i]=0;
            e[i].clear();
            in[i].clear();
            edge[i].clear();
        }
        rep(i,2,n){
            sci(u);
            e[u].pb(i);
        }
        rep(i,1,n-1){
            scanf("%d%lld",&x[i],&y[i]);
            ans[i]=0;
            now[x[i]]=y[i];
        }
        res=0;
        dfs(1,0,0);
        // rep(i,1,n){
        //     printf("i:%d par:%d\n",i,par[i]);
        // }
        rep(i,1,n){
            int u=i,v=i%n+1;
            if(dep[u]<dep[v])swap(u,v);
            //printf("i:%d u:%d v:%d\n",i,u,v);
            while(dep[u]!=dep[v]){
                edge[i].pb(u);
                u=par[u];
            }
            while(u!=v){
                edge[i].pb(u);
                u=par[u];
                edge[i].pb(v);
                v=par[v];
            }
            for(auto &z:edge[i]){
                //printf("(%d,%d) z:%d\n",i,i%n+1,z);
                res+=now[z];
                in[z].pb(i);
            }
        }
        int cnt=0;
        ll del=0;
        per(i,n-1,1){
            ans[i]=res+1ll*del*cnt;
            //now[x[i]]=0;
            for(auto &z:in[x[i]]){
                res-=y[i];
                unknow[z]++;
                if(unknow[z]==1)cnt++;
            }
            del+=y[i];
            //printf("i:%d cnt:%d cnt2:%d add:%d y:%lld\n",i,cnt,cnt2,add,y[i]);
        }
        rep(i,1,n-1){
            printf("%lld%c",ans[i]," \n"[i==n-1]);
        }
    }
    return 0;
}