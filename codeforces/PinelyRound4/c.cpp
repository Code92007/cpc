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
int t,n,a[N];
bool sol(){
    vector<int>ans;
    rep(j,1,40){
        int mx=0,mn=1e9;
        bool sm=1;
        rep(i,1,n){
            sm&=(!a[i]);
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        if(sm){
            pte(SZ(ans));
            for(auto &v:ans){
                printf("%d ",v);
            }
            puts("");       
            return 1;
        }
        int v=(mx+mn)/2;
        ans.pb(v);
        rep(i,1,n){
            a[i]=abs(a[i]-v);
        }
    }
    return 0;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
        }
        if(!sol())puts("-1");
    }
    return 0;
}