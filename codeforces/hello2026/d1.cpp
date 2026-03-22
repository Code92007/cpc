#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
#define ull unsigned long long
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
int t,n,k,u,v,dep[N],ans;
vector<int>e[N];
void dfs(int u,int fa,int d){
    //printf("u:%d fa:%d d:%d\n",u,fa,d);
    dep[d]++;
    ans=max(ans,dep[d]);
    int cnt=0;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u,d+1);
        cnt++;
    }
    ans=max(ans,cnt+1);
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        ans=0;
        rep(i,0,n){
            e[i].clear();
            dep[i]=0;
        }
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(1,0,0);
        pte(ans);
    }
    return 0;
}
/*
*/