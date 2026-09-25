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
int t,n;
int ask(int u,int v,int d){
    printf("? %d %d %d\n",u,v,d);
    fflush(stdout);
    int w;
    scanf("%d",&w);
    return w;
}
void out(int u,int v,int d){
    printf("! %d %d %d\n",u,v,d);
    fflush(stdout);
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        int mxp=1,mxd=0,st=1;
        rep(i,2,n){
            int x=ask(st,i,mxd+1);
            if(!x)continue;
            mxp=i,mxd++;
            while(ask(st,i,mxd+1))mxd++;
        }
        swap(st,mxp);
        rep(i,1,n){
            if(i==st)continue;
            int x=ask(st,i,mxd+1);
            if(!x)continue;
            mxp=i,mxd++;
            while(ask(st,i,mxd+1))mxd++;
        }
        out(st,mxp,mxd);
    }
    return 0;
}