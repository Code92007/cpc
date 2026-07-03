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
const int N=64,mod=998244353;
int t,cnt2,cnt3;
double f[N][N],g[N][N],p=0.25;
ll n;
void add(db &x,db y){
    x+=y;
}
int main(){
    scanf("%d%lld",&t,&n);
    cnt2=cnt3=0;
    while(n%2==0)n/=2,cnt2++;
    while(n%3==0)n/=3,cnt3++;
    if(n>1){
        puts("0");
        return 0;
    }
    //printf("cnt2:%d cnt3:%d\n",cnt2,cnt3);
    f[0][0]=1;
    rep(i,1,t){
        rep(j,0,cnt2){
            rep(k,0,cnt3){
                g[j][k]=0;
            }
        }
        rep(j,0,cnt2){
            rep(k,0,cnt3){
                add(g[j][k],p*f[j][k]);
                add(g[min(cnt2,j+1)][k],p*f[j][k]);
                add(g[j][min(cnt3,k+1)],p*f[j][k]);
                add(g[min(cnt2,j+2)][k],p*f[j][k]);
            }
        }
        rep(j,0,cnt2){
            rep(k,0,cnt3){
                f[j][k]=g[j][k];
            }
        }
    }
    //printf("db:%lf\n",f[cnt2][cnt3]);
    ll ans=f[cnt2][cnt3]*100000;
    printf("%lld\n",ans);
    return 0;
}
/*
1/(n-1)^2-1/(n+1)^2=n^2^
*/