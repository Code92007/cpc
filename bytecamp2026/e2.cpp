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
const int N=65;
ll n,m,f[N],s[N],x[N];
int sz;
vector<ll>now;
int ans=100;
void upd(int &x,int y){
    x=min(x,y);
}
void dfs(int i,int mx,int cnt,ll xo){
    printf("i:%d mx:%d cnt:%d xo:%lld\n",i,mx,cnt,xo);
    if(i==sz){
        if(xo==n)upd(ans,cnt);
        return;
    }
    int p=now[i];
    ll w=f[p];
    int tot=1;
    dfs(i+1,p,cnt+tot,xo^w);
    for(int j=p-2;j>mx;j-=2){
        w^=f[j+2];
        w^=f[j+1];
        w^=f[j];
        tot++;
        dfs(i+1,p-1,cnt+tot,xo^w);
    }
}
void sol(){
    f[1]=s[1]=x[1]=1;
    rep(i,2,60){
        f[i]=f[i-1]+f[i-2];
        x[i]=x[i-1]^f[i];
        s[i]=s[i-1]+f[i];
    }
    rep(i,1,60){
        if(s[i]==m && x[i]==n){
            upd(ans,i);
        }
    }
    ll y=0;
    per(i,60,1){
        if(m>=f[i]){
            m-=f[i];
            y^=f[i];
            now.pb(i);
        }
    }
    reverse(now.begin(),now.end());
    sz=SZ(now);
    //if(y==n)upd(ans,sz);
    if(now[0]==2)now[0]=1;
    //printf("now0:%d sz:%d\n",now[0],sz);
    dfs(0,0,0,0);
    if(ans>=60)puts("-1");
    else printf("%d\n",ans);
}
int main(){
    scanf("%lld%lld",&n,&m);
    sol();
    return 0;
}
/*
1 1 2 3 5 8 13 21 34 55 89
*/