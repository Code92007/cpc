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
typedef pair<ll,int> P;
typedef array<int,3> A;
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
int t;
ll n;
int main(){
    sci(t);
    while(t--){
        scanf("%lld",&n);
        ll v=n%12,x=n-v;
        if(v<10){
            printf("%lld %lld\n",v,x);
            continue;
        }
        else if(v==10){
            if(n==10)puts("-1");
            else{
                printf("%lld %lld\n",22,n-22);
            }
        }
        else{
            printf("%lld %lld\n",11,n-11);
        }
    }
    return 0;
}