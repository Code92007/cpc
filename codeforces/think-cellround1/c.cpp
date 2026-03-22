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
int t,n,a[N],b[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
            b[i]=a[i]+i;
        }
        sort(b+1,b+n+1,greater<int>());
        rep(i,2,n){
            if(b[i]>=b[i-1])b[i]=b[i-1]-1;
        }
        rep(i,1,n){
            printf("%d%c",b[i]," \n"[i==n]);
        }
    }
    return 0;
}
/*

3 4 5
5 4 3

*/