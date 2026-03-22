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
const int N=2e5+10;//H[200000]=12.78
int n;
ll v;
db ans[N],res;
map<ll,int>p,q;
int main(){
    sci(n);
    rep(i,1,n){
        ans[i]=ans[i-1]+1./i;
        scanf("%lld",&v);
        p[v]++;
        rep(j,1,13){
            if(v%j==0)q[v/j]++;
        }
    }
    for(auto &x:q){
        ll v=x.fi;
        int cnt=x.se;
        //printf("v:%lld cnt:%d\n",v,cnt);
        res=max(res,1.*v*ans[cnt]);
    }
    printf("%.8lf\n",res);
    return 0;
}
