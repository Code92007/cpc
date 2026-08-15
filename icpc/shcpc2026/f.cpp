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
typedef pair<int,int> P;
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
const int N=5e6+10,M=10,K=512,L=9,INF=0x3f3f3f3f;
int t,n,nex[N][M],dp[K][L];
char s[N];
P pre[K][L];
bool ckmax(int &x,int y){
    if(x<y){x=y;return 1;}
    return 0;
}
bool ckmin(int &x,int y){
    if(x>y){x=y;return 1;}
    return 0;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        rep(j,0,9)nex[n+1][j]=n+1;
        per(i,n,1){
            rep(j,0,9){
                nex[i][j]=nex[i+1][j];
            }
            nex[i][s[i]-'0']=i;
        }
        memset(dp,INF,sizeof dp);
        memset(pre,0,sizeof pre);
        dp[0][0]=0;
        int up=(1<<9)-1;
        rep(i,0,up){
            rep(j,0,8){
                if(dp[i][j]>n)continue;
                rep(k,1,8){
                    int nj=(j+k)%9,p=nex[dp[i][j]+1][k];
                    if(!nj)continue;
                    if(i>>nj&1)continue;
                    if(p>n)continue;
                    int ni=i|(1<<nj);
                    if(ckmin(dp[ni][nj],p)){
                        pre[ni][nj]=P(i,j);
                    }
                }
            }
        }
        int sz=0;
        P st=P(0,0);
        vector<int>res;
        rep(i,0,up){
            rep(j,0,8){
                if(dp[i][j]>n)continue;
                if(ckmax(sz,__builtin_popcount(i))){
                    st=P(i,j);
                }
            }
        }
        while(SZ(res)<sz){
            auto [x,y]=st;
            res.pb(dp[x][y]);
            st=pre[x][y];
        }
        printf("%d",sz);
        per(i,sz-1,0){
            printf(" %d",res[i]);
        }
        puts("");
    }
    return 0;
}