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
const int INF=(1<<30)-1+(1<<30);
int t,x,y,p,q,ans,ap,aq;
int mx(int n,int y,int lim,int res,bool has){
    if(n==-1){
        if(has)return res;
        else return INF;
    }
    int lb=lim>>n&1,ly=y>>n&1;
    if(has)return mx(n-1,y,lim,res,has);
    int ans=1<<30;
    rep(i,0,1){
        if(i==1 && lb)continue;
        if(!has && i<ly)continue;
        int w=(i==0?0:1<<n);
        ans=min(ans,mx(n-1,y,lim,res+w,has||(i>ly)));
    }
    return ans;
}
int mn(int n,int y,int lim,int res,bool has){
    if(n==-1)return res;
    int lb=lim>>n&1,ly=y>>n&1;
    //if(has)return mn(n-1,y,lim,res,has);
    if(has && lb==0)return mn(n-1,y,lim,res+(1<<n),has);
    int ans=0;
    rep(i,0,1){
        if(i==1 && lb)continue;
        if(!has && i>ly)continue;
        int w=(i==0?0:1<<n);
        ans=max(ans,mn(n-1,y,lim,res+w,has||(i<ly)));
    }
    return ans;
}
int main(){
    sci(t);
    while(t--){
        sci(x),sci(y);
        p=x;
        q=mx(30,y,p,0,0);
        ans=x+y;
        //printf("x:%d y:%d\n",x,y);
        ll w=abs(x-p)+abs(y-q);
        if(ans>w)ans=w,ap=p,aq=q;
        //printf("ans:%d %d %d\n",ans,ap,aq);
        //ans=x+y;///////
        q=mn(30,y,p,0,0);
        w=abs(x-p)+abs(y-q);
        if(ans>w)ans=w,ap=p,aq=q;
        //printf("ans:%d %d %d\n",ans,ap,aq);
        //ans=x+y;///////
        q=y;
        p=mx(30,x,q,0,0);
        w=abs(x-p)+abs(y-q);
        if(ans>w)ans=w,ap=p,aq=q;
        //printf("ans:%d %d %d\n",ans,ap,aq);
        //ans=x+y;///////
        q=y;
        p=mn(30,x,q,0,0);
        w=abs(x-p)+abs(y-q);
        if(ans>w)ans=w,ap=p,aq=q;
        printf("%d %d\n",ap,aq);
    }
}