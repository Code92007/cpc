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
const int N=1e6+10,M=2e6+10,K=2e6,INF=0x3f3f3f3f;
int n,p[N],c[N],m,tp[N],tc[N],d[N],ans[N];
int mp[M],mc[M],mn=INF;
void upd(int &x,int y){
    x=min(x,y);
}
int cal(int v,int l1,int l2){
    if(v==INF)return INF;
    if(v<l1)return 0;
    if(v<l2)return v;
    return l2;
}
int main(){
    memset(mp,INF,sizeof mp);
    memset(mc,INF,sizeof mc);
    sci(n);
    rep(i,1,n)sci(p[i]);
    rep(i,1,n){
        sci(c[i]);
        upd(mp[p[i]],c[i]);
        upd(mc[c[i]],p[i]);
        upd(mn,c[i]+p[i]);
    }
    rep(i,1,K){
        upd(mp[i],mp[i-1]);
        upd(mc[i],mc[i-1]);
    }
    sci(m);
    rep(i,1,m)sci(tp[i]);
    rep(i,1,m)sci(tc[i]);
    rep(i,1,m){
        sci(d[i]);
        ans[i]=mn;
        int sump=tp[i]+d[i],sumc=tc[i]+d[i],lp=tp[i]-1,lc=tc[i]-1;
        if(lp>=0)upd(ans[i],cal(mp[lp],tc[i],sumc));
        if(lc>=0)upd(ans[i],cal(mc[lc],tp[i],sump));
        upd(ans[i],sump+mp[K]);
        upd(ans[i],sumc+mc[K]);
        printf("%d\n",ans[i]);
    }
    return 0;
}