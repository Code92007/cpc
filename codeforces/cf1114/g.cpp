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
const int N=2e5+10;
int t,n,a[N],p[N],leaf;
vector<int>e[N];
map<int,int>now[N];
ll sum;
priority_queue<int>q;
void dfs(int u){
    int son=0;
    for(auto &v:e[u]){
        dfs(v);
        if(SZ(now[u])<SZ(now[v])){
            now[u].swap(now[v]);
        }
        for(auto &x:now[v]){
            now[u][x.fi]+=x.se;
        }
        son++;
    }
    if(!son){
        leaf++;
        now[u][a[u]]++;
        sum+=a[u];
    }
    else{
        auto it=*now[u].begin();
        if(a[u]>it.fi){
            sum+=a[u]-it.fi;
            now[u][it.fi]--;
            q.push(it.fi);
            if(now[u][it.fi]==0)now[u].erase(it.fi);
            now[u][a[u]]++;
        }
        else{
            q.push(a[u]);
        }
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        sum=0;
        leaf=0;
        while(!q.empty())q.pop();
        rep(i,1,n){
            now[i].clear();
            sci(a[i]);
            e[i].clear();
        }
        rep(i,2,n){
            sci(p[i]);
            e[p[i]].pb(i);
        }
        dfs(1);
        rep(i,1,leaf-1){
            printf("%d ",-1);
        }
        rep(i,leaf,n){
            printf("%lld",sum);
            if(!q.empty()){
                int v=q.top();
                q.pop();
                sum+=v;
            }
            if(i!=n)putchar(' ');
        }
        puts("");
    }
    return 0;
}