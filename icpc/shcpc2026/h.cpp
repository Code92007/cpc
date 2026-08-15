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
const int N=5e5+10;
int n,t[N],x[N],b[N];
int main(){
    sci(n);
    rep(i,1,n){
        sci(t[i]),sci(x[i]);
    }
    int now=t[n]+1;
    per(i,n,1){
        int w=x[i];
        now=min(now-w,t[i]-x[i]);
        b[i]=now;
    }
    if(b[1]<0){
        puts("No");
        return 0;
    }
    puts("Yes");
    rep(i,1,n){
        printf("%d%c",b[i]+1," \n"[i==n]);
    }
    return 0;
}