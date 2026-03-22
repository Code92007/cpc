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
const ll INF=1e18;
int t,x,y,v;
P dp[31][2][2][4],res;
bool has[31][2][2][4];
//1:x-p 0:p-x
//2:y-q 0:q-y
P dfs(int n,bool lx,bool ly,int i,ll res,ll nx){
    if(res>=INF)return P(INF,nx);
    if(n==-1)return P(res,nx);
    if(has[n][lx][ly][i])return dp[n][lx][ly][i];
    int xb=x>>n&1,yb=y>>n&1;
    bool hp=i&1,hq=i&2;
    P &ans=dp[n][lx][ly][i];
    ans.fi=INF;
    ll mnw=INF;
    int zp=-1;
    rep(vp,0,1){
        rep(vq,0,1){
            if(vp==1 && vq==1)continue;
            if(!lx){
                if(hp && vp>xb)continue;
                if(!hp && vp<xb)continue;
            }
            if(!ly){
                if(hq && vq>yb)continue;
                if(!hq && vq<yb)continue;
            }
            bool okx=(i&1)?(vp<xb):(vp>xb);
            bool oky=(i&2)?(vq<yb):(vq>yb);
            ll w=0;
            if(hp)w-=vp;
            else w+=vp;
            if(hq)w-=vq;
            else w+=vq;
            if(mnw>w)mnw=w,zp=vp;
            // if(!lx || !ly){
            //     
            P z=dfs(n-1,lx||okx,ly||oky,i,res+w,nx||(1<<n));
            if(z.fi<ans.fi)ans=z;
            //}
        }
    }
    if(~zp){
        mnw=1ll*mnw*(1ll<<n);
        if(lx && ly){
            if(zp==0){
                P z=dfs(n-1,lx,ly,i,res+mnw,nx);
                if(z.fi<ans.fi)ans=z;
            }
            else{
                P z=dfs(n-1,lx,ly,i,res+mnw,nx||(1<<n));
                if(z.fi<ans.fi)ans=z;
            }
        }
    }
    has[n][lx][ly][i]=1;
    return ans;
}
int main(){
    sci(t);
    while(t--){
        sci(x),sci(y);
        memset(has,0,sizeof has);
        ll ans=x+y,p,q;
        rep(i,0,3){
            P z=dfs(30,0,0,i,0,0);
            printf("i:%d z:%lld nx:%lld\n",i,z.fi,z.se);
            if(i==0){
                ll w=z.fi-x-y;
                if(w>ans)ans=w,p=z.se,q=ans-p;
            }
            if(i==1){
                ll w=z.fi+x-y;
                if(w>ans)ans=w,p=z.se,q=ans+p;
                //ans=min(ans,v+x-y);//q-p min
            }
            if(i==2){
                ll w=z.fi-x+y;
                if(w>ans)ans=w,p=z.se,q=-ans+p;
                //ans=min(ans,v-x+y);//p-q min
            }
            if(i==3){
                ll w=z.fi+x+y;
                if(w>ans)ans=w,p=z.se,q=-(ans+p);
                //ans=min(ans,v+x+y);//-p-q min
            }
        }
        printf("ans:%lld\n",ans);
        printf("%lld %lld\n",p,q);
    }
}