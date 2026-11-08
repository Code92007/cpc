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
const int INF=0x3f3f3f3f;
vector<int>a;
int t,n,v;
int sol(vector<int>b){
    if(b.empty())return 0;
    int ans=INF;
    bool one=1;
    for(auto &v:b){
        one&=(v==1);
    }
    if(one)return 5;
    rep(k,0,41){
        bool ok=1;
        vector<int>nex;
        for(auto &v:b){
            int w=v+k;
            if(w%42==0)nex.pb(w/42);
            else if(w%6==0)continue;
            else ok=0;
        }
        if(!ok)continue;
        int cost=sol(nex);
        if(cost!=INF)cost=42*cost+k;
        ans=min(ans,cost);
    }
    return ans;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        a.clear();
        rep(i,1,n){
            sci(v);
            a.pb(v);
        }
        int ans=sol(a);
        if(ans==INF)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}