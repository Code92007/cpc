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
const int N=2e5+5;
int n,a[N],ans;
ll sum,mn;
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        sum+=a[i];
        mn=min(mn,sum);
    }
    if(mn>=0)ans++;
    //printf("mn:%lld\n",mn);
    per(i,n,2){
        mn+=a[i];
        mn=min(mn,1ll*a[i]);
        if(mn>=0)ans++;
    }
    pte(ans);
    return 0;
}
//    1 -1 2 1 3
//  2 3 1 4 3
//1 2 0 3 2