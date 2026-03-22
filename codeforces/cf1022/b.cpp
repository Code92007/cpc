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
typedef pair<int,int> P;
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
const int N=3e5+10;
int t,n,x;
int sol(){
    if(x==0){
        if(n==1)return -1;
        if(n%2==0)return n;
        return n+3;//01 10 11 1+2+3
    }
    int l=1,r=__builtin_popcount(x);
    if(r==1){
        if(n&1)return n-1+x;
        else{
            if(x==1)return n+3;//1 1 2 3
            else return n+x;//1 1 1 3
        }
    }
    else{
        int one=max(0,n-r);
        if(one&1)one++;
        return one+x;
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);sci(x);
        pte(sol());
    }
    return 0;
}
/*

3 4 5
5 4 3

*/