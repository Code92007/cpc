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
using namespace std;
const int N=510,K=65;
const ll INF=1e18;
int n,m,u,v,w,now;
ll ans;
bitset<N>f[2][K][N],g,tmp;
int main(){
    sci(n),sci(m);
    for(int i=1;i<=m;i++){
        sci(u),sci(v),sci(w);
        f[w][0][u][v]=1;
    }
    for(int i=1;i<=60;i++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(f[0][i-1][u][v]){
                    f[0][i][u]|=f[1][i-1][v];
                }
                if(f[1][i-1][u][v]){
                    f[1][i][u]|=f[0][i-1][v];
                }
            }
        }
    }
    if(f[0][60][1].count()){
        puts("-1");
        return 0;
    }
    now=0;
    tmp[1]=1;
    for(int i=60;i>=0;i--){
        g.reset();
        for(int j=1;j<=n;j++){
            if(tmp[j]) g|=f[now][i][j];
        }
        if(g.count()!=0){
            now^=1;
            tmp=g;
            ans+=1ll<<i;
        }
    }
    if(ans>INF) puts("-1");
    else printf("%lld\n",ans);
    return 0;
}
