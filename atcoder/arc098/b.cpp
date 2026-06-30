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
const int N=2e5+10;
int n,a[N],ans;
ll xo[N],sum[N];
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        xo[i]=xo[i-1]^a[i];
        sum[i]=sum[i-1]+a[i];
    }
    rep(i,1,n){
        int j=max(0,i-20);
        rep(k,j,i-1){
            if(sum[i]-sum[k]==(xo[i]^xo[k]))ans++;
        }
    }
    pte(ans);
    return 0;
}