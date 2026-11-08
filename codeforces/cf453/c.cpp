//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=3e5+10;
typedef long long ll;
typedef array<int,3> A;
int n,m,q,u,v,mxr[N],par[N];
vector<int>e[N];
vector<A>ask;
bool in[N],vis[N];
ll res[N];
struct BIT{
	int n;
    ll tr[N];
	void init(int _n){
		n=_n;
		memset(tr,0,(n+1)*sizeof(*tr));
	}
	void add(int x,ll v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]+=v;
	}
	ll sum(int x){
        if(x<=0)return 0;
		ll ans=0; 
		for(int i=x;i;i-=i&-i)
		ans+=tr[i];
		return ans;
	}
    ll cal(int l,int r){
        return sum(r)-sum(l-1);
    }
}tr,tr2;
void dfs(int u,int fa){
    par[u]=fa;
    vis[u]=1;
    in[u]=1;
    for(auto &v:e[u]){
        if(v==fa)continue;
        if(!vis[v])dfs(v,u);
        else if(in[v]){
            int mn=v,mx=v;
            for(int z=u;z!=v;z=par[z]){
                mn=min(mn,z);
                mx=max(mx,z);
            }
            mxr[mx]=mn;
        }
    }
    in[u]=0;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i])dfs(i,0);
    }
    tr.init(n);
    tr2.init(n);
    for(int i=2;i<=n;++i){
        mxr[i]=max(mxr[i],mxr[i-1]);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        A x;
        scanf("%d%d",&x[1],&x[0]);
        x[2]=i;
        ask.push_back(x);
    }
    sort(ask.begin(),ask.end());
    int now=1;
    for(auto &x:ask){
        int l=x[1],r=x[0],id=x[2];
        while(now<=r){
            if(mxr[now]>0){
                tr.add(mxr[now],1);
                tr2.add(mxr[now],mxr[now]);
            }
            now++;
        }
        ll ans=1ll*(l+r)*(r-l+1)/2;
        int len=r-l+1,low=len-tr.cal(l,r);
        ans-=1ll*low*(l-1);
        ans-=tr2.cal(l,r);
        res[id]=ans;
    }
    for(int i=1;i<=q;++i){
        printf("%lld",res[i]);
        puts("");
    }
    return 0;
}