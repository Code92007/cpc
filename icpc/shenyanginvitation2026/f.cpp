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
bool used[N*N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        memset(a,-1,sizeof a);
        memset(used,0,sizeof used);
        a[0][0]=2*n-1;a[n-1][n-1]=2*n-2;
        used[a[0][0]]=1;
        used[a[n-1][n-1]]=1;
        int c=(n+2)/4;
        ll sum=0;
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(i==0 && j==0)continue;
                if(i==n-1 && j==n-1)continue;
                if(i!=0 && j!=n-1)continue;
                while(used[c])c++;
                //printf("i:%d j:%d c:%d\n",i,j,c);
                a[i][j]=c++;
                used[a[i][j]]=1;
                sum+=a[i][j];
            }
        }
        int tot=n-2;
        c=0;
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(i==0 && j==0)continue;
                if(i==n-1 && j==n-1)continue;
                if(i!=j)continue;
                while(used[c])c++;
                c=max(c,sum/tot);
                tot--;
                a[i][j]=c;
                if(tot==0)a[i][j]=sum;
                //assert(!used[sum]);
                used[a[i][j]]=1;
                sum-=a[i][j];
            }
        }
        c=n*n-1;
        rep(i,0,n-1){
            rep(j,0,n-1){
                while(used[c])c--;
                if(a[i][j]==-1)a[i][j]=c--;
                //assert(a[i][j]>=0);
                //assert(a[i][j]<=n*n-1);
                printf("%d%c",a[i][j]," \n"[j==n-1]);
            }
        }
    }
    return 0;
}