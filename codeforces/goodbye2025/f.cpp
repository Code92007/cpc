//#include<bits/stdc++.h>
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
const int N=2e5+10,mod=998244353;
int t,n,u,v,sz[N],fac[N];
vector<int>e[N],ans;
int modpow(int x,int n,int mod){
    int res=1;
    for(;n;n/=2,x=1ll*x*x%mod){
        if(n&1)res=1ll*res*x%mod;
    }
    return res;
}
void dfs(int u,int fa){
    sz[u]=1;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    //printf("u:%d szu:%d\n",u,sz[u]);
    if(sz[u]%2==0 && u!=1){
        ans.pb(sz[u]);
        sz[u]=0;
    }
}
void init(){
    fac[0]=1;
    rep(i,1,N-5){
        fac[i]=1ll*fac[i-1]*i%mod;
    }
}
int main(){
    init();
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            e[i].clear();
        }
        ans.clear();
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(1,0);
        if(ans.empty()){
            puts("1");
            continue;
        }
        int res=1,prod=1,cnt=0,sum=0;
        for(auto &v:ans){
            cnt++;
            prod=1ll*prod*v%mod;
        }
        res=1ll*fac[cnt-1]%mod*prod%mod;
        for(auto &v:ans){
            int inv=1ll*modpow(v,mod-2,mod);
            int otherprod=1ll*prod*inv%mod;
            sum=(sum+otherprod)%mod;
        }
        res=1ll*res*sum%mod;
        res=1ll*res*sz[1]%mod;
        printf("%d\n",res);
    }
    return 0;
}
/*
按白色和白色的父亲边把树切割成若干个连通块，也就是森林，
不妨最后一个样例，三个连通块，其中A=4，B=4，C=2，

则答案=4*4*2*(ABC+ACB+BAC+BCA+CAB+CBA)
其中ABC的贡献是4*4，ACB的贡献是4*2

注意到C结尾，则C对乘积没有贡献，
记prod=A*B*C=4*4*2，则C结尾的贡献是2!*(prod/C)

其余同理，答案就是(2!)*prod*(prod/A+prod/B+prod/C)

还需要乘以sz[1]，因为1如果是白色的话，不能操作

所以答案就是sz[1]*(m-1)!*prod*sum (prod/v) for v in ans
*/