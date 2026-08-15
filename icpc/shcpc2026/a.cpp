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
const int N=505,off=2e5+10;
int bs[2]={19260817,19491001};
int mod[2]={1000000007,1000000009};
int n,m,sz,a[N][N],hs[2][N],pw[2][N],cnt;
vector<P>w[N];
int cal(int k,int l,int r){
    return ((1ll*hs[k][r]-1ll*hs[k][l]*pw[k][r-l]%mod[k])%mod[k]+mod[k])%mod[k];
}
int main(){
    sci(n),sci(m),sci(sz);
    rep(i,1,n){
        rep(j,1,m){
            sci(a[i][j]);
        }
    }
    rep(j,1,m){
        rep(k,0,1){
            hs[k][0]=pw[k][0]=1;
            rep(i,1,n){
                int w=a[i][j]-a[i-1][j]+off;
                pw[k][i]=1ll*pw[k][i-1]*bs[k]%mod[k];
                hs[k][i]=(1ll*hs[k][i-1]*bs[k]+w)%mod[k];
            }
        }
        rep(i,sz,n){
            w[j].pb(P(cal(0,i-sz+1,i),cal(1,i-sz+1,i)));
        }
        sort(w[j].begin(),w[j].end());
    }
    rep(j,1,m){
        rep(k,j+1,m){
            int x=n-sz+1,y=0,z=0;
            while(y<x && z<x){
                if(w[j][y]<w[k][z])y++;
                else if(w[j][y]>w[k][z])z++;
                else{
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}