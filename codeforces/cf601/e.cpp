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
const int N=1e3+10;
int n,m,a[N],id[N],b[N][N];
/*
5
4 1 5 3 4
不排序 会重复
6
10101
11001
10100
10110
00111
00111
排序 不重复
6
10110
11000
11100
11110
11111
*/
int main(){
    sci(n);
    rep(i,0,n-1){
        sci(a[i]);
        id[i]=i;
    }
    sort(id,id+n,[&](int x,int y){
        return a[x]>a[y];
    });
    m=n+1;
    rep(i,0,n-1){
        int p=id[i],v=a[p];
        rep(j,0,v-1){
            b[(i+j)%m][p]=1;
        }
    }
    pte(m);
    rep(i,0,m-1){
        rep(j,0,n-1){
            printf("%d",b[i][j]);
        }
        puts("");
    }
    return 0;
}