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
int t,x,y;
bool ok(int x,int y,int xk){
    if(xk<0)return 0;
    ll nx=1ll*x+xk,ny=1ll*y+xk;
    return nx+ny==(nx^ny);
}
int main(){
    sci(t);
    while(t--){
        int k=-1;
        sci(x),sci(y);
        rep(i,0,30){
            int z=1<<i;
            int nx=z;
            int ny=z;
            rep(j,i+1,30){
                if(x>>j&1)nx|=1<<j;
                if(y>>j&1)ny|=1<<j;
            }
            int xk=nx-x,yk=ny-y;
            if(k==-1 && ok(x,y,xk))k=xk;
            if(k==-1 && ok(x,y,yk))k=yk;
            //printf("i:%d xk:%d yk:%d\n",i,xk,yk);
        }
        pte(k);
    }
    return 0;
}