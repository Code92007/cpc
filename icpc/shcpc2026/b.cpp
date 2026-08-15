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
const int N=5e3+10;
int n,m,Q,a[N][N],x,y;
short sg[N][N],in[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
queue<P>q;
bool ok(int x,int y){
    return x>=1 && x<=n && y>=1 && y<=m;
}
int main(){
    sci(n),sci(m),sci(Q);
    rep(i,1,n){
        rep(j,1,m){
            sci(a[i][j]);
        }
    }
    memset(sg,-1,sizeof sg);
    rep(i,1,n){
        rep(j,1,m){
            rep(k,0,3){
                int ni=i+dx[k],nj=j+dy[k];
                if(!ok(ni,nj))continue;
                if(a[i][j]>a[ni][nj]){
                    in[ni][nj]++;
                }
            }
        }
    }
    rep(i,1,n){
        rep(j,1,m){
            if(!in[i][j]){
                q.push(P(i,j));
                sg[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();
        rep(k,0,3){
            int ni=i+dx[k],nj=j+dy[k];
            if(!ok(ni,nj))continue;
            if(~sg[ni][nj])continue;
            if((--in[ni][nj])==0){
                int w=0;
                rep(z,0,3){
                    int zi=ni+dx[z],zj=nj+dy[z];
                    if(!ok(zi,zj))continue;
                    if(sg[zi][zj]==0)w=1;
                }
                sg[ni][nj]=w;
                q.push(P(ni,nj));
            }
        }
    }
    while(Q--){
        sci(x),sci(y);
        puts(sg[x][y]?"1":"0");
    }
    return 0;
}