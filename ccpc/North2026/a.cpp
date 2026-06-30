#include<bits/stdc++.h>
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
const int N=1e5+10,M=6,INF=0x3f3f3f3f;
int n,a[N],f[M][M][M],g[M][M][M],ans;//(第一维最后，第二维最初，第二维最后)
void upd(int &x,int y){
    x=max(x,y);
}
int cal(int x,int y){
    return (y-x+5)%5;
}
int main(){
    sci(n);
    memset(f,128,sizeof f);
    memset(g,128,sizeof g);
    f[0][0][0]=0;
    rep(i,1,n){
        sci(a[i]);
        rep(j,0,5){
            rep(k,0,5){
                rep(l,0,5){
                    if(f[j][k][l]<0)continue;
                    //放第一堆
                    if(j==0){//第一堆还没放
                        upd(g[a[i]][k][l],f[j][k][l]+1);
                    }
                    else{
                        upd(g[a[i]][k][l],f[j][k][l]+cal(j,a[i])+1);
                    }
                    //放第二堆
                    if(k==0){//第二堆还没放
                        if(l!=0)continue;
                        upd(g[j][a[i]][a[i]],f[j][k][l]+1);
                    }
                    else{//第二堆已经放了
                        upd(g[j][k][a[i]],f[j][k][l]+cal(l,a[i])+1);
                    }
                }
            }
        }
        rep(j,0,5){
            rep(k,0,5){
                rep(l,0,5){
                    f[j][k][l]=g[j][k][l];
                    g[j][k][l]=-INF;
                }
            }
        }
    }
    rep(j,0,5){
        rep(k,0,5){
            rep(l,0,5){
                if(f[j][k][l]<0)continue;
                if(j && k){
                    f[j][k][l]+=cal(j,k);
                }
                upd(ans,f[j][k][l]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}