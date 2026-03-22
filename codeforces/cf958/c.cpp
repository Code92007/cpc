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
int t;
ll n;
int main(){
    sci(t);
    while(t--){
        scanf("%lld",&n);
        vector<ll>ans;
        per(i,60,0){
            if(n>>i&1){
                ll w=n^(1ll<<i);
                if(w)ans.pb(w);
            }
        }
        ans.pb(n);
        pte(SZ(ans));
        for(auto &v:ans){
            printf("%lld ",v);
        }
        puts("");
    }
    return 0;
}