#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
//f[i][0]表示到i的时候已经结束的方案 f[i][1]表示还没结束的方案
int n,h[N],f[N][2],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&h[i]);
        h[i]--;
    }
    h[n+1]=h[n];
    for(int i=1;i<=n;++i){
        f[i][0]=(1ll*f[i-1][1]*min(h[i-1],h[i])%mod+h[i])%mod;
        f[i][1]=(1ll*f[i-1][1]*min({h[i-1],h[i],h[i+1]})%mod+min(h[i],h[i+1]))%mod;
        ans=(ans+f[i][0])%mod;
    }
    printf("%d\n",ans);
    return 0;
}