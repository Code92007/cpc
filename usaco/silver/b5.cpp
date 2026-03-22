
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<ll,ll> P;
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
const int N=2e5+10,M=4e5+10;
int t,n,m,x[M],y[M],col[N],cyc;
bool vis[N],has[N],ok;
ll l[N],r[N],ans[N],z[M];
vector<int>stk,tmp;
map<P,ll>mp;
vector<P>e[N],add;
bool dfs(int u){
    vis[u]=1;
    for(auto &x:e[u]){
        int v=x.fi;
        ll w=x.se;
        if(has[v]){
            if(ans[u]+ans[v]!=w)return 0;
        }
        else{
            has[v]=1;
            ans[v]=1ll*w-ans[u];
        }
        if(!vis[v]){
            if(!dfs(v))return 0;
        }
    }
    return 1;
}
bool dfs2(int u,int c){
    tmp.pb(u);
    vis[u]=1;
    col[u]=c;
    stk.pb(u);
    if(cyc)return 0;
    for(auto &x:e[u]){
        int v=x.fi;
        ll w=x.se;
        if(cyc)return 0;
        if(vis[v]){
            if(col[v]!=-c){//有奇环
                //printf("u:%d v:%d colu:%d\n",u,v,col[u]);
                ll all=0;
                int las=v,sg=1;
                while(!stk.empty()){
                    int pre=stk.back();
                    stk.pop_back();
                    ll val=mp[P(pre,las)];
                    //printf("val:%d\n",val);
                    all+=1ll*sg*val;
                    sg=-sg;
                    las=pre;
                    if(las==v)break;
                }
                //printf("all:%lld\n",all);
                if(all%2)ok=0;
                if(has[v] && ans[v]!=all/2)ok=0;
                has[v]=1;
                ans[v]=all/2;//奇环求值 重新dfs一遍
                cyc=v;
                return 0;
            }
            continue;
        }
        if(!dfs2(v,-c))return 0;
    }
    stk.pop_back();
    return 1;
}
void dfs3(int u,int c,ll z){
    tmp.pb(u);
    vis[u]=1;
    col[u]=c;
    ans[u]=z;
    ll L,R;
    if(col[u]>0)L=l[u]-ans[u],R=r[u]-ans[u];
    else L=ans[u]-r[u],R=ans[u]-l[u];
    add.pb(P(L,1));
    add.pb(P(R+1,-1));
    for(auto &x:e[u]){
        int v=x.fi;
        ll w=x.se;
        if(vis[v])continue;
        dfs3(v,-c,w-z);
    }
}
bool sol(){
    rep(i,1,m){
        scanf("%d%d%lld",&x[i],&y[i],&z[i]);
        // if(x[i]==y[i]){
        //     if(z[i]&1){
        //         ok=0;
        //         continue;
        //     }
        //     int p=x[i];
        //     if(!has[p]){
        //         ans[p]=z[i]/2;
        //         has[p]=1;
        //     }
        //     else{
        //         if(ans[p]!=z[i]/2)ok=0;
        //     }
        //     continue;
        // }
        if(x[i]>y[i])swap(x[i],y[i]);
        int u=x[i],v=y[i];
        // if(has[u] && has[v]){
        //     if(ans[u]+ans[v]!=z[i])ok=0;
        // }
        // else if(has[u]){
        //     has[v]=true;
        //     ans[v]=z[i]-ans[u];
        // }
        // else if(has[v]){
        //     has[u]=true;
        //     ans[u]=z[i]-ans[v];
        // }
        if(mp.count(P(u,v))){
            if(mp[P(u,v)]!=z[i])ok=0;
        }
        else{
            mp[P(u,v)]=mp[P(v,u)]=z[i];
            e[x[i]].pb(P(y[i],z[i]));
            if(x[i]!=y[i])e[y[i]].pb(P(x[i],z[i]));
        }
    }
    if(!ok)return 0;
    // rep(i,1,m){
    //     //if(x[i]==y[i])continue;
    //     e[x[i]].pb(P(y[i],z[i]));
    //     if(x[i]!=y[i])e[y[i]].pb(P(x[i],z[i]));
    // }
    // rep(i,1,n){
    //     if(!vis[i] && has[i]){
    //         if(!dfs(i))return 0;//自环的
    //     }
    // }
    rep(i,1,n){
        if(!vis[i]){
            stk.clear();
            tmp.clear();
            cyc=0;
            if(!dfs2(i,1)){
                if(!ok)return 0;
                for(auto &v:tmp){
                    vis[v]=col[v]=0;
                    if(v!=cyc)has[v]=ans[v]=0;
                }
                stk.clear();
                tmp.clear();
                if(!dfs(cyc))return 0;
            }
        }
    }
    if(!ok)return 0;
    rep(i,1,n)vis[i]=0;
    // rep(i,1,n){
    //     if(!vis[i] && has[i]){
    //         if(!dfs(i))return 0;//给连通块确定值
    //     }
    // }
    int res=0;
    rep(i,1,n){
        if(has[i]){
            if(l[i]<=ans[i] && ans[i]<=r[i]){
                res++;
            }
        }
    }
    rep(i,1,n){
        if(!vis[i] && !has[i]){
            add.clear();
            tmp.clear();
            dfs3(i,1,0);//二分图偶环的
            sort(add.begin(),add.end());
            int sz=add.size(),now=0,mx=0;
            ll w=0;
            for(int j=0;j<sz;){
                int k=j;
                while(k+1<sz && add[k+1].fi==add[j].fi){
                    k++;
                }
                rep(x,j,k){
                    now+=add[x].se;
                }
                mx=max(mx,now);
                if(mx==now)w=add[k+1].fi;
                j=k+1;
            }
            res+=mx;
            has[i]=1;
            ans[i]=w;
            for(auto &v:tmp)vis[v]=0;
            if(!dfs(i))return 0;
        }
    }
    printf("%d\n",res);
    return 1;
}
int main(){
    sci(t);
    while(t--){
        scanf("%d%d",&n,&m);
        ok=1;
        mp.clear();
        rep(i,1,n){
            scanf("%lld",&l[i]);
            has[i]=0;
            vis[i]=0;
            col[i]=0;
            ans[i]=0;
            e[i].clear();
        }
        rep(i,1,n){
            scanf("%lld",&r[i]);
        }
        if(!sol())puts("-1");
    }
    return 0;
}