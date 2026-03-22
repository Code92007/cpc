#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;
#define ull unsigned long long
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
const int N=505;
int n,k,q,r,c,val,a[N][N],sum[N][N],now;
int main(){
    sci(n),sci(k),sci(q);
    while(q--){
        sci(r),sci(c),sci(val);
        int x=min(n,r+k-1),y=min(n,c+k-1);
        int delta=val-a[r][c];
        rep(i,r,x){
            rep(j,c,y){
                sum[i][j]+=delta;
                now=max(now,sum[i][j]);
            }
        }
        a[r][c]=val;
        printf("%d\n",now);
    }
    return 0;
}