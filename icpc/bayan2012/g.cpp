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
const int N=305;
int n,x[N],p[N];
int main(){
    n=302;
    printf("%d\n",n);
    x[1]=1;p[1]=1e6;
    x[2]=1e5;p[2]=310;
    rep(i,3,301){
        p[i]=p[i-1]-1;
        x[i]=x[i-1]+p[i]+p[i-1];
    }
    x[302]=1e6;p[302]=1e6;
    rep(i,1,302){
        printf("%d %d\n",x[i],p[i]);
    }
    return 0;
}