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
const int N=1e3+10;
int n,m,a[N][N],p;
int dx[2]={1,0},dy[2]={0,1};
int main(){
    sci(n),sci(m);
    if(n==m || n==m-1 || n==m+1){
        a[1][1]=1;
        if(n<=m)p=1;
        else p=0;
        int x=1,y=1;
        while(true){
            x+=dx[p],y+=dy[p];
            a[x][y]=1;
            p^=1;
            if(x==n && y==m)break;
        }
        rep(i,1,n){
            rep(j,1,m){
                printf("%d",a[i][j]);
            }
            puts("");
        }
    }
    else{
        puts("-1");
    }
    return 0;
}