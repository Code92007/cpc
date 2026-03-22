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
typedef pair<ll,ll> P;
typedef array<ll,3> A;
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
const int N=3e6+10,M=10;
int n,dp[N][M];
queue<P>q;
P pre[N][M];
int stk[N],c;
void out(int r,int v){
    while(dp[r][v]>0){
        stk[++c]=v;
        auto [x,y]=pre[r][v];
        r=x,v=y;
    }
    reverse(stk+1,stk+c+1);
    rep(i,1,c)printf("%d",stk[i]);
}
void sol(){
    rep(i,1,9){
        q.push(P(i%n,i));
        dp[i%n][i]=1;
        pre[i%n][i]=P(0,0);
    }
    rep(j,0,9){
        if(~dp[0][j]){
            printf("%d\n",j);
            return;
        }
    }
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        int r=x.fi,las=x.se;
        //printf("i:%d r:%d las:%d\n",i,r,las);
        if(r==0){
            out(r,las);
            return;
        }
        rep(j,las,9){
            int v=(r*10+j)%n;
            //printf("j:%d v:%d\n",j,v);
            if(dp[v][j]==-1){
                dp[v][j]=dp[r][las]+1;
                pre[v][j]=P(r,las);
                q.push(P(v,j));
            }
        }
    }
    puts("-1");
}
int main(){
    memset(dp,-1,sizeof dp);
    sci(n);
    sol();
    return 0;
}