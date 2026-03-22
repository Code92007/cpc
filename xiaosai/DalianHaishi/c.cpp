//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
#include<unordered_map>
#include<set>
#define ll long long
#define ull unsigned ll
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef double db;
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
using namespace std;
int T,n,m,a,b;
bool sol(){
    int x=(n/2)*(m/2);
    if(x!=a+b)return 0;
    if(n==1 || m==1 || n%2==0 || m%2==0)return 0;
    vector<vector<char>>ans(n+1,vector<char>(m+1,'0'));
    rep(i,1,n){
        rep(j,1,m){
            if(i%2==0 && j%2==0)ans[i][j]='t';
        }
    }
    for(int i=2;i<=n;i+=2){
        for(int j=3;j<=m-2;j+=4){
            if(b<2)break;
            ans[i][j]='1';
            b-=2;
        }
    }
    if(b>0){
        for(int i=n-1;i>=2;i-=2){
            int x=m-1,cnt=0;
            for(int y=-1;y<=1;++y){
                for(int z=-1;z<=1;++z){
                    if(ans[i+y][x+z]=='1')cnt++;
                }
            }
            if(cnt%2==0)ans[i][x+1]='1',b--;
            if(b==0)break;
        }
    }
    puts("YES");
    rep(i,1,n){
        rep(j,1,m){
            putchar(ans[i][j]);
        }
        puts("");
    }
    return 1;
}
int main(){
    sci(T);
    while(T--){
        sci(n),sci(m),sci(a),sci(b);
        if(!sol()){
            puts("NO");
        }
    }
    return 0;
}