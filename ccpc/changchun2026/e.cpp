//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
int t,n,a[4];
vector<int>stk;
bool vis[10];
bool dfs(int x,int up,int c){
    stk.pb(x);
    if(!c)return 1;
    vis[x]=1;
    rep(i,1,3){
        if(x+i<=up && !vis[x+i] && dfs(x+i,up,c-1))return 1;
        if(x-i>=1 && !vis[x-i] && dfs(x-i,up,c-1))return 1;
    }
    stk.pop_back();
    return 0;
}
bool sol(){
    rep(i,1,5){
        memset(vis,0,sizeof vis);
        if(dfs(1,i,i)){
            
        }
    }
}
int main(){
    sci(t);
    while(t--){
        stk.clear();
        sci(n);
        rep(i,1,3)sci(a[i]);
        if(!sol())puts("-1");
        else{

        }
    }
    return 0;
}