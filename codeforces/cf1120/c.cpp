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
const int N=1e3+10,M=N*N;
int t,n,k,a[N][N];
bool sol(){
    if(k<n || k>2*n-1)return 0;
    //x+2y=k x+y=n
    rep(i,1,n){
        rep(j,1,n){
            a[i][j]=0;
        }
    }
    int y=k-n,x=n-y,c=0;
    //printf("x:%d\n",x);
    rep(i,1,x){
        a[i][i]=++c;
        //printf("c:%d\n",c);
    }
    int p=x;
    rep(i,p+1,n){
        a[p][i]=++c;
        //printf("a[%d][%d]:%d\n",p,i,a[p][i]);
    }
    rep(i,p+1,n){
        a[i][p]=++c;
    }
    rep(i,1,n){
        rep(j,1,n){
            if(!a[i][j])a[i][j]=++c;
            printf("%d%c",a[i][j]," \n"[j==n]);
        }
    }
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        if(!sol())puts("-1");
    }
    return 0;
}