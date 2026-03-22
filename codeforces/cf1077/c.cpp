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
const int N=2e5+10;
int t,n,a[N],b[N];
vector<int>p;
int main(){
    sci(t);
    while(t--){
        sci(n);
        int mn=1e9,mx=0;
        rep(i,1,n){
            sci(a[i]);
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        p.clear();
        rep(i,1,n){
            if(a[i]!=b[i]){
                p.pb(b[i]);
            }
        }
        if(p.empty()){
            puts("-1");
            continue;
        }
        int ans=1e9;
        //printf("mx:%d mn:%d\n",mx,mn);
        for(auto &v:p){
            ans=min(ans,max(mx-v,v-mn));
        }
        //printf("ans:%d res:%d\n",ans,res);
        pte(ans);
    }
    return 0;
}