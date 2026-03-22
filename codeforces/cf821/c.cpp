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
const int N=1e5+10;
int t,n,a[N];
vector<P>ans;
void out(int l,int r){
    ans.pb(P(l,r));
}
void sol(){
    ans.clear();
    if(n==1){
        puts("0");
        return;
    }
    out(1,n);
    int v=(a[1]+a[n])%2?a[1]:a[n];
    rep(i,2,n-1){
        int x=(v+a[i])%2;
        if(x)out(1,i);
        else out(i,n);
    }
    pte(SZ(ans));
    for(auto &x:ans){
        printf("%d %d\n",x.fi,x.se);
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n)sci(a[i]);
        sol();
    }
    return 0;
}