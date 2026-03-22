#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
#define ull unsigned long long
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
const int N=250,M=1<<15,mod=1e9+7;
int f[M][2][2],g[M][2][2];
int n,m;//dp[k][l][x]表示当前扫到(i,j) 列的覆盖state是k 同行左侧的覆盖情况是l(0/1) 当前累计有x个空地没被覆盖（这些空地的位置<=(i,j))时的方案数
char s[N][N];
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    sci(n),sci(m);
    rep(i,0,n-1){
        scanf("%s",s[i]);
    }
    if(n<m){
        rep(i,0,n-1){
            rep(j,0,m-1){
                if(i<j)swap(s[i][j],s[j][i]);
            }
        }
        swap(n,m);
    }
    s[n][0]='x';
    // vector<vector<vector<int>>>f(1<<m,vector<vector<int>>(2,vector<int>(2,0)));
    // auto g=f;
    if(s[0][0]=='x'){
        add(f[0][0][0],1);
    }
    else{
        add(f[0][0][1],1);
        add(f[1][1][0],1);
    }
    int up=1<<m;
    rep(i,0,n-1){
        rep(j,0,m-1){
            int nx,ny;
            if(j+1<m)nx=i,ny=j+1;
            else nx=i+1,ny=0;
            rep(k,0,up-1){
                rep(l,0,1){
                    rep(x,0,1){
                        int w=f[k][l][x],st=1<<ny;
                        f[k][l][x]=0;
                        if(!w)continue;
                        if(s[nx][ny]=='.'){
                            bool cov=(k&st)>0;
                            int nl;
                            if(ny==0){
                                nl=0;
                            }
                            else{
                                nl=l;
                                cov|=(l==1);
                            }
                            int all=x+(!cov);
                            if(all<=1)add(g[k][nl][all],w);//不选
                            add(g[k|st][1][x],w);//选
                        }
                        else{
                            add(g[k&(~st)][0][x],w);//不选，并且把之前横竖视线阻断
                        }
                    }
                }
            }
            rep(k,0,up-1){
                rep(l,0,1){
                    rep(x,0,1){
                        swap(f[k][l][x],g[k][l][x]);
                    }
                }
            }
            // printf("i:%d j:%d\n",i,j);
            // rep(k,0,up-1){
            //     rep(l,0,1){
            //         rep(x,0,1){
            //             printf("k:%d l:%d x:%d dp:%d\n",k,l,x,f[k][l][x]);
            //         }
            //     }
            // }
        }
    }
    int ans=0;
    rep(k,0,up-1){
        rep(l,0,1){
            rep(x,0,1){
                add(ans,f[k][l][x]);
            }
        }
    }
    pte(ans);
    return 0;
}