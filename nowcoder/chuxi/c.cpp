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
typedef pair<int,int> P;
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
const int N=105;
int n,m;
ll a[N],b[N],c[N][N];
ll gcd(ll x,ll y){
    return !y?x:gcd(y,x%y);
}
int main(){
    sci(n),sci(m);
    rep(i,1,n){
        scanf("%lld",&a[i]);
    }
    rep(i,1,m){
        scanf("%lld",&b[i]);
    }
    rep(i,1,n){
        rep(j,1,m){
            ll g=gcd(a[i],b[j]);
            c[i][j]=g;
            a[i]/=g;b[j]/=g;
            printf("%lld%c",c[i][j]," \n"[j==m]);
        }
    }
    return 0;
}