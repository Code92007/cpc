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
const int N=2e5+10;
int t,n,c[2][2],d[2][2];
char a[N],b[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s%s",a+1,b+1);
        rep(i,0,1)rep(j,0,1)c[i][j]=d[i][j]=0;
        rep(i,1,n){
            int f=i%2,x=a[i]-'0',y=b[i]-'0';
            c[f][x]++;
            d[f][y]++;
        }
        bool no=0;
        rep(i,0,1)rep(j,0,1)no|=(c[i][j]!=d[i][j]);
        puts(no?"NO":"YES");
    }
    return 0;
}