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
const int N=505;
int n,m,a[N][N],b[N][N],ans;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool ok(int x,int y){
    return x>=1 && x<=n && y>=1 && y<=m;
}
void op(int i,int j){
    int w=a[i][j]-b[i][j];
    if(w<=0)return;
    int cnt=0;
    rep(k,0,3){
        int ni=i+dx[k],nj=j+dy[k];
        if(!ok(ni,nj))continue;
        cnt++;
    }
    int v=cnt+1,x=(w+v-1)/v;
    ans+=x;
    b[i][j]+=x*v;
    rep(k,0,3){
        int ni=i+dx[k],nj=j+dy[k];
        if(!ok(ni,nj))continue;
        b[ni][nj]-=x;
    }
}
int main(){
    sci(n),sci(m);
    rep(i,1,n){
        rep(j,1,m){
            sci(a[i][j]);
        }
    }
    rep(z,1,500){
        rep(i,1,n){
            rep(j,1,m){
                op(i,j);
            }
        }
        per(i,n,1){
            per(j,m,1){
                op(i,j);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}