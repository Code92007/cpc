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
int t;
ll n,k;
vector<ll>ans;
bool sol(){
    if(n<k)return 0;
    ll v=n/k,x=n/v;
    if(x==k){
        ans.pb(v);
        return 1;
    }
    ll up=min(v+10,n);
    for(ll i=v;i<=up;++i){
        
    }
    //6/4=1 x=6 k=4
    //ax+by=n
    return 0;
}
int main(){
    sci(t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        if(!sol())puts("NO");
        else{
            puts("YES");
            printf("%d\n",SZ(ans));
            for(auto &v:ans){
                printf("%lld ",v);
            }
            puts("");
        }
        ans.clear();
    }
    return 0;
}