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
typedef pair<ll,ll> P;
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
int n,id[N];
ll ans,c,lef,w[N],v[N],k[N],dp[100];
vector<P>used[10];
int main(){
    scanf("%d%lld",&n,&c);
    rep(i,1,n){
        scanf("%lld%lld%lld",&w[i],&v[i],&k[i]);
        id[i]=i;
    }
    sort(id+1,id+n+1,[&](int x,int y){
        return 1ll*v[x]*w[y]>1ll*v[y]*w[x];
    });
    rep(p,1,n){
        int i=id[p];
        ll cnt=min(1ll*k[i],c/w[i]);
        ans+=1ll*cnt*v[i];
        k[i]-=cnt;
        c-=1ll*w[i]*cnt;
        used[w[i]].pb(P(i,cnt));
    }
    rep(i,1,3){
        if(used[i].empty())continue;
        int tot=0;
        while(!used[i].empty()){
            auto z=used[i].back();
            int p=z.fi,cnt=min(1ll*z.se,3ll-tot);
            k[p]+=cnt;
            ans-=1ll*cnt*v[p];
            c+=1ll*cnt*w[p];
            tot+=cnt;
            z.se-=cnt;
            if(!z.se)used[i].pop_back();
            if(tot==3)break;
        }
    }
    rep(p,1,n){
        int i=id[p];
        ll num=min(1ll*k[i],c/w[i]);
        rep(j,1,num){
            per(u,c,w[i]){
                dp[u]=max(dp[u],dp[u-w[i]]+v[i]);
            }
        }
    }
    rep(i,1,c){
        dp[i]=max(dp[i],dp[i-1]);
    }
    printf("%lld\n",dp[c]+ans);
    return 0;
}