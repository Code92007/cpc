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
const int N=305,M=601;
int t,n,m,pr[N],c;
ll a[N][N];
bool no[M];
int main(){
    for(int i=2;i<M;++i){
        if(!no[i])pr[++c]=i;
        for(int j=2*i;j<M;j+=i){
            no[j]=1;
        }
    }
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,0,n-1){
            rep(j,0,m-1){
                a[i][j]=1;
            }
        }
        //ll ans=1;
        rep(k,1,c){
            int w=pr[k];
            if(w>=n+m)break;
            rep(i,0,n-1){
                int st=((w-1-i+m)%m+m)%m;
                for(int j=st;j<m;j+=w){
                    a[i][j]*=w;
                }
            }
        }
        rep(i,0,n-1){
            rep(j,0,m-1){
                //ans=max(ans,a[i][j]);
                printf("%lld%c",a[i][j]," \n"[j==m-1]);
            }
        }
        //ptlle(ans);
    }
    return 0;
}
/*
0101
1010
  011
 01110
01110
 110
  0
  10
  
*/