//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
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
const int N=105,M=2*N;
int t,n,a[M][M];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n-1)a[i][n]=n;
        rep(i,1,n)a[n][i]=1;
        rep(i,1,n)a[n][n+i]=n*n;
        rep(i,1,n)a[n+i][n]=n*n*n;
        int m=2*n;
        rep(i,1,m){
            rep(j,1,m){
                printf("%d%c",a[i][j]," \n"[j==m]);
                a[i][j]=0;
            }
        }
    }
    return 0;
}
