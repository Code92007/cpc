//#include<bits/stdc++.h>
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
typedef array<int,3> A;
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
const int N=3e5+10;
int n,m,u,v,cnt[N],par[N],sz[N],ans[N],del;
vector<int>sma[N],rev[N],big[N];
bool used[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
void un(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    par[y]=x;
    sz[x]+=sz[y];
}
void dfs(int i,int mx){
    if(find(i)!=find(1))return;
    while(!big[i].empty()){
        int v=big[i].back();
        big[i].pop_back();
        bool ok=(find(v)!=find(1));
        un(i,v);
        if(ok)dfs(v,mx);
    }
    while(!sma[i].empty()){
        int v=sma[i].back();
        if(v>mx)break;
        sma[i].pop_back();
        bool ok=(find(v)!=find(1));
        un(i,v);
        if(ok)dfs(v,mx);
    }
}
int main(){
    sci(n),sci(m);
    rep(i,1,n)par[i]=i,sz[i]=1;
    rep(i,1,m){
        sci(u),sci(v);
        if(u==v)continue;
        //if(u>v)swap(u,v);
        if(u<v){
            sma[u].pb(v);
            rev[v].pb(u);
        }
        else{
            big[u].pb(v);
        }
    }
    rep(i,1,n){
        sort(sma[i].begin(),sma[i].end(),greater<int>());
        for(auto &v:sma[i]){
            cnt[v]++;
            if(cnt[v]==1)del++;
        }
        if(cnt[i]>0){
            cnt[i]=0;
            del--;
        }
        for(auto &v:rev[i]){
            if(find(1)!=find(v))continue;
            un(v,i);
        }
        dfs(i,i);
        if(sz[find(1)]==i)pte(del);
        else puts("-1");
    }
    return 0;
}
/*
4 3
1 4
4 2
2 3
*/