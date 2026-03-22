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
int t,n,u,v,rt,ls,rs;
vector<int>e[N];
vector<P>ans;
void dfs(int u,int fa,bool up){
    for(auto &v:e[u]){
        if(v==fa)continue;
        if(up)ans.pb(P(v,u));
        else ans.pb(P(u,v));
        dfs(v,u,up^1);
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n)e[i].clear();
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        rt=0;
        rep(i,1,n){
            if(SZ(e[i])==2){
                rt=i;  
                ls=e[i][0];
                rs=e[i][1];
                break;
            }
        }
        if(!rt){
            puts("NO");
            continue;
        }
        ans.clear();
        ans.pb(P(rt,ls));
        ans.pb(P(rs,rt));
        dfs(ls,rt,1);
        dfs(rs,rt,0);
        puts("YES");
        for(auto &x:ans){
            printf("%d %d\n",x.fi,x.se);
        }
    }
    return 0;
}