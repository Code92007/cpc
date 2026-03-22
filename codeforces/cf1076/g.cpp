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
int t,n,u,v,ans[N];
vector<P>ck;
vector<int>e[N];
//最极端情况n=3一条链，dfs了中间那个点，可能会被hack掉
int dfs(int u,int fa){
    int las=u;
    for(auto &v:e[u]){
        if(v==fa)continue;
        int res=dfs(v,u);
        if(res==-1)continue;
        if(las==-1)las=res;
        else{
            ck.pb(P(las,res));
            las=-1;
        }
    }
    return las;
}
int ask(int u,int v){
    printf("? %d %d\n",u,v);
    fflush(stdout);
    int w;
    scanf("%d",&w);
    return w;
}
void out(int x){
    printf("! %d\n",x);
    fflush(stdout);
}
void sol(P x){
    int p=ask(x.fi,x.fi);
    if(p==1)out(x.fi);
    else out(x.se);
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        ck.clear();
        rep(i,1,n){
            e[i].clear();
        }
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        int las=dfs(1,0);
        bool ok=0;
        for(auto &x:ck){
            if(ask(x.fi,x.se)==1){
                sol(x);
                ok=1;
                break;
            }
        }
        if(!ok)out(las);
    }
    return 0;
}