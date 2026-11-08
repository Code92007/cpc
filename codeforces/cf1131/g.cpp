#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353;
int t,n,u,v,ans,x[N],y[N],dep[N];
vector<int>e[N];
bool dfs(int u,int fa,int d,int w,int add){
    int b=x[u]^y[u]^add;
    if(dep[d]==-1){
        dep[d]=b;
        if(b)ans=(ans+w)%mod;
    }
    else if(dep[d]!=b)return 0;
    int nex=(x[u]+b+add)/2;
    for(auto &v:e[u]){
        if(v==fa)continue;
        if(!dfs(v,u,d+1,2ll*w%mod,nex))return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=n;++i){
            e[i].clear();
            dep[i]=-1;
        }
        for(int i=2;i<=n;++i){
            scanf("%d",&u);
            scanf("%d",&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;++i){
            scanf("%1d",&x[i]);
        }
        for(int i=1;i<=n;++i){
            scanf("%1d",&y[i]);
        }
        ans=0;
        if(!dfs(1,0,0,1,0))puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}