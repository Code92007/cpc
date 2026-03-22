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
const int N=2e5+10;
int t,n,a[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        a[n]=1;
        rep(i,2,n-1){
            a[i]=i^1;
        }
        if(n&1)a[1]=n^1;
        else a[1]=n;
        rep(i,1,n){
            printf("%d%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}
/*
1 2 3 4 5
4 3 2 5 1
1 2 3 4 5 6
2 1      1 
*/