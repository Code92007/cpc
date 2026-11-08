//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define id(x) (x+n)
const int N=2e4+10,mod=1e9+7;
int T,n,m,c[N],mask[N],cnt[N];
int F[N],G[N],fac[N],inv[N],ifac[N];
void add(int &x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
void init(){
    fac[0]=ifac[0]=inv[1]=1;
    for(int i=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%mod;
    for(int i=2;i<N;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<N;++i)ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
}
void clear(){
    for(int i=1;i<=n;++i)c[i]=0;
    for(int i=1;i<=m;++i)mask[i]=cnt[i]=0;
    for(int i=-n;i<=n;++i)F[i+n]=G[i+n]=0;
}
int modpow(int x,int n,int mod){
    x=(x+mod)%mod;
    int res=1;
    for(;n;n/=2,x=1ll*x*x%mod){
        if(n&1)res=1ll*res*x%mod;
    }
    return res;
}
int sol(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&c[i]);
        cnt[c[i]]++;
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&mask[i]);
    }
    if(n==1){
        for(int i=1;i<=m;++i){
            if(mask[i])return 0;
        }
        return 1;
    }
    if(n==2){
        (mask[c[1]]+=1)%=2;
        (mask[c[2]]+=1)%=2;
        for(int i=1;i<=m;++i){
            if(mask[i])return 0;
        }
        return 1;
    }
    F[id(0)]=1;
    for(int i=1;i<=m;++i){
        int sg=(cnt[i]%2)^mask[i],w=cnt[i];
        for(int j=-n;j<=n;++j){
            G[id(j)]=F[id(j)];
            F[id(j)]=0;
        }
        for(int j=-n;j<=n;++j){
            if(j+w<=n)add(F[id(j+w)],1ll*inv[2]*G[id(j)]%mod);
            if(j-w>=-n)add(F[id(j-w)],1ll*(!sg?inv[2]:mod-inv[2])*G[id(j)]%mod);
        }
    }
    int ans=0;
    for(int i=-n;i<=n;++i){
        add(ans,1ll*modpow(i,n-2,mod)*F[id(i)]%mod*ifac[n-2]%mod);
    }
    ans=1ll*ans*fac[n-2]%mod;
    return ans;
}
int main(){
    init();
    scanf("%d",&T);
    while(T--){
        printf("%d\n",sol());
        clear();
    }
    return 0;
}