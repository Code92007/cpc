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
const int N=3e3+10,mod=998244353;
int t,n,k,a[N];
int modpow(int x,int n,int mod){
    int res=1;
    for(;n;n/=2,x=1ll*x*x%mod){
        if(n&1)res=1ll*res*x%mod;
    }
    return res;
}
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;++i){
            scanf("%d",&a[i]);
        }
        vector<int>f(n,0);
        f[0]=1;
        rep(i,1,n){
            vector<int>g(n,0);
            rep(j,0,n-1){
                rep(x,1,k){
                    if(j>=a[x]){
                        add(g[j],f[j-a[x]]);
                    }
                }
            }
            f.swap(g);
        }
        int inv=modpow(n,mod-2,mod);
        printf("%lld\n",1ll*f[n-1]*inv%mod);
    }
    return 0;
}