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
const int N=12;
int n,p[N],q[N];
ll cal(int *a){
    ll all=0;
    rep(i,1,n){
        int res=1,cnt=1;
        rep(j,i+1,n){
            res*=cnt;
            cnt++;
        }
        int tot=0;
        rep(j,i+1,n){
            if(a[i]>a[j])tot++;
        }
        all+=1ll*tot*res;
    }
    return all;
}
int main(){
    sci(n);
    rep(i,1,n)sci(p[i]);
    rep(i,1,n)sci(q[i]);
    //printf("p:%lld\n",cal(p));
    //printf("q:%lld\n",cal(q));
    ll w=max(cal(q)-cal(p)-1,0ll);
    ptlle(w);
    return 0;
}