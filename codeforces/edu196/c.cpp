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
const int N=2e5+10,M=20;
int t,n,d[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        int now=0;
        rep(i,1,n){
            now^=i;
            d[i]=0;
        }
        int w=1;
        while(w*2<=n)w*=2;
        for(;w>=1;w/=2){
            int nw=w*2;
            if(now&nw)continue;
            now^=nw;
            now^=w;
            d[w]=1;
        }
        rep(i,1,n){
            printf("%d%c",d[i]," \n"[i==n]);
        }
    }
    return 0;
}