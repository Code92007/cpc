//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=2e3+10;
int t,n,a[N][N],c;
int main(){
    sci(t);
    while(t--){
        sci(n);
        c=0;
        rep(i,0,n-1){
            a[0][i]=c;
            used[c]=1;
            c++;
        }
        rep(i,1,n-1){
            a[i][n-1]=c++;
        }
        c=n*n-1;
        per(i,n-1,1){
            per(j,n-2,0){
                a[i][j]=c--;
            }
        }
        rep(i,0,n-1){
            rep(j,0,n-1){
                printf("%d%c",a[i][j]," \n"[j==n-1]);
            }
        }
    }
    return 0;
}
/*
1 0
3 2
0 1 2
3 4 5
6 7 8
*/