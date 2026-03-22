#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
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
int n,a[N],b[N],ans[N];
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        if(i>1)b[i-1]=a[i]-a[i-1];
    }
    sort(b+1,b+n,greater<int>());
    per(i,n-1,1){
        ans[i]=ans[i+1]+b[i];
    }
    rep(i,1,n){
        printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}
