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
int t;
ll a,b,n;
int main(){
    sci(t);
    while(t--){
        scanf("%lld%lld%lld",&a,&b,&n);
        if(n<=a+2*(b-1))puts("Alice");
        else if(n>a+2*(2*b-1))puts("Bob");
        else if(n<3*a)puts("Bob");
        else puts("Alice");
    }
    return 0;
}