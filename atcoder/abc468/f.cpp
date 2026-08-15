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
const int N=5e5+10,mod=998244353,INF=0x3f3f3f3f;
int n,p[N];
int f[N],g[N],ans,mx;
int main(){
    sci(n);
    rep(i,1,n){
        sci(p[i]);
        f[i]=g[i]=INF;
    }
    rep(i,1,n){
        //int x=lower_bound(f+1,f+n+1,p[i])-f;
        //int y=lower_bound(g+1,g+n+1,p[i])-g;
        //if(f[x]==INF)f[x]=p[i],p[i]=0,ans++;
        //f[x]=p[i];
        if(mx<p[i])mx=p[i],p[i]=0,ans++;
    }
    //printf("ans:%d\n",ans);
    rep(i,1,n){
        if(!p[i])continue;
        int y=lower_bound(g+1,g+n+1,p[i])-g;
        if(g[y]==INF)ans++;
        g[y]=p[i];
    }
    pte(ans);
    return 0;
}