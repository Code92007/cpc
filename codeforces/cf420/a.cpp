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
const int N=105;
int n,a[N][N];
bool sol(){
    rep(i,1,n){
        rep(j,1,n){
            bool ok=0;
            if(a[i][j]==1)continue;
            rep(x,1,n){
                rep(y,1,n){
                    if(a[i][j]==a[i][x]+a[y][j])ok=1;
                }
            }
            //printf("i:%d j:%d ok:%1d\n",i,j,ok);
            if(!ok)return 0;
        }
    }
    return 1;
}
int main(){
    sci(n);
    rep(i,1,n){
        rep(j,1,n){
            sci(a[i][j]);
        }
    }
    puts(sol()?"Yes":"No");
    return 0;
}