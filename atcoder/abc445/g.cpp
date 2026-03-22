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
const int N=5e5+10,mod=998244353;
int n,a[N],dp[N],sum[N],nex[N];
vector<int>pos[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        pos[a[i]].pb(i);
    }
    rep(i,1,n){
        int las=-1;
        for(auto &v:pos[i]){
            if(~las)nex[las]=v;
            las=v;
        }
    }
    rep(i,1,n){
        if(SZ(pos[i])<i){
            pos[i].clear();
        }
    }
    int ans=0;
    per(i,n,1){
        sum[i]=sum[i+1];
        int v=a[i];
        if(pos[v].empty()){
            continue;
        }
        int x=lower_bound(pos[v].begin(),pos[v].end(),i)-pos[v].begin();
        if(x+v-1>SZ(pos[v])-1)continue;
        int p=pos[v][x+v-1];
        add(dp[i],p+1>n?1:1+sum[p+1]);
        if(x+v<=SZ(pos[v])-1){
            int p2=pos[v][x+v];
            add(dp[i],mod-dp[p2]);
        }
        add(sum[i],dp[i]);
        if(nex[i]){
            add(sum[i],mod-dp[nex[i]]);
        }
        if(x==0)add(ans,dp[i]);
    }
    pte(ans);
    return 0;
}