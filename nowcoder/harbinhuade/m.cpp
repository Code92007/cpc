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
const int N=505;
int n;
ll a[N][N],dis[N][N];
int main(){
    sci(n);
    rep(i,1,n){
        rep(j,1,n){
            sci(dis[i][j]);
        }
    }
    rep(k,1,n){
        rep(i,1,n){
            rep(j,1,n){
                dis[i][j]=max(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    return 0;
}