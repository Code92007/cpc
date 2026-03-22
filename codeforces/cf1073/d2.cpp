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
const int N=105,mod=998244353;
int t,n,f[N][N][2][3],g[N][N][2][3];
char s[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        memset(f,0,sizeof f);
        memset(g,0,sizeof g);
        f[0][0][0][0]=1;
        rep(i,1,n){
            int w=(s[i]=='(')?1:-1;
            rep(j,0,i-1){
                rep(k,0,i-1){
                    rep(x,0,1){
                        rep(y,0,2){
                            //不选
                            add(g[j][k][x][y],f[j][k][x][y]);
                            //选
                            if(k+w>=0){
                                int nx=x || (s[i]==')');
                                int ny=!x?0:min(2,y+(s[i]=='('));
                                add(g[j+1][k+w][nx][ny],f[j][k][x][y]);
                            }
                            f[j][k][x][y]=0;
                        }
                    }
                }
            }
            rep(j,0,i){
                rep(k,0,i){
                    rep(x,0,1){
                        rep(y,0,2){
                            f[j][k][x][y]=g[j][k][x][y];
                            g[j][k][x][y]=0;
                            //if(f[j][k][x][y])printf("i:%d j:%d k:%d x:%d y:%d f:%d\n",i,j,k,x,y,f[j][k][x][y]);
                        }
                    }
                }
            }
        }
        int ans=0;
        rep(j,1,n){
            add(ans,1ll*f[j][0][1][2]*(j-2)%mod);
        }
        pte(ans);
    }
    return 0;
}