//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
const int N=1e6+10;
int n,a[N];
int main(){
    sci(n);
    rep(i,1,n)sci(a[i]);
    long long ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            for (int i = l; i <= r; i++) {
                ans += a[i] * (i - l + 1);
            }
        }
    }
    ptlle(ans);
    return 0;
}
//[1,7]  [1,3] [3,7]
//1个1 2个2 3个3 3个4 3个5 2个6 1个7
//1个8 2个8 3个8
//[1,5] [1,3] [3,5]
//1个1 2个2 3个3 2个4 1个5
//