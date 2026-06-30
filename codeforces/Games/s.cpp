//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
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
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N];
int main(){
    sci(n);
    rep(i,1,n)sci(a[i]);
    if(a[1]<a[n])reverse(a+1,a+n+1);
    int l=1,r=1;
    rep(i,2,n){
        if(a[i]>a[i-1])l++;
        else break;
    }
    per(i,n-1,1){
        if(a[i]>a[i+1])r++;
        else break;
    }
    //pprintf("l:%d r:%d\n",l,r);
    l%=2;r%=2;
    if(l||r)puts("Alice");
    else puts("Bob");
    return 0;
}