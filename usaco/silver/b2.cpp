//#include<bits/stdc++.h>
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
typedef pair<int,int> P;
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
const int N=2e5+10;
int t,n,m,x[N],y[N],z[N],col[N];
bool vis[N],has[N],ok;
ll l[N],r[N],ans[N];
vector<int>stk;
map<P,int>mp;
vector<P>e[N];
vector<pair<ll,int> >add;
bool dfs(int u){
    vis[u]=1;
    for(auto &x:e[u]){
        int v=x.fi,w=x.se;
        if(has[v]){
            if(ans[u]+ans[v]!=w)return 0;
        }
        else{
            has[v]=1;
            ans[v]=w-ans[u];
        }
        if(!vis[v]){
            if(!dfs(v))return 0;
        }
    }
    return 1;
}
bool dfs2(int u,int c){
    vis[u]=1;
    col[u]=c;
    stk.pb(u);
    for(auto &x:e[u]){
        int v=x.fi,w=x.se;
        if(vis[v]){
            if(col[v]!=0 && col[v]!=-c){//有奇环
                ll all=0;
                int las=v,sg=1;
                while(!stk.empty()){
                    int pre=stk.back();
                    stk.pop_back();
                    int val=mp[P(pre,las)];
                    all+=sg*val;
                    sg=-sg;
                    las=pre;
                    if(las==v)break;
                }
                if(all%2)ok=0;
                has[v]=1;
                ans[v]=all/2;//奇环求值 重新dfs一遍
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
    //printf("u:%d c:%d z:%lld\n",u,c,z);
    vis[u]=1;
    col[u]=c;
    ans[u]=z;
    ll L,R;
    //printf("u:%d ans:%lld l:%lld r:%lld\n",u,ans[u],l[u],r[u]);
    if(col[u]>0)L=l[u]-ans[u],R=r[u]-ans[u];
    else L=ans[u]-r[u],R=ans[u]-l[u];
    //printf("u:%d L:%lld R:%lld\n",u,L,R);
    add.pb(P(L,1));
    add.pb(P(R+1,-1));
    for(auto &x:e[u]){
        int v=x.fi,w=x.se;
        if(vis[v])continue;
        dfs3(v,-c,w-z);
    }
}
bool sol(){
    rep(i,1,m){
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        if(x[i]==y[i]){
            if(z[i]&1){
                ok=0;
                continue;
            }
            int p=x[i];
            if(!has[p]){
                ans[p]=z[i]/2;
                has[p]=1;
            }
            else{
                if(ans[p]!=z[i]/2)ok=0;
            }
            continue;
        }
        if(x[i]>y[i])swap(x[i],y[i]);
        int u=x[i],v=y[i];
        if(has[u] && has[v]){
            if(ans[u]+ans[v]!=z[i])ok=0;
        }
        else if(has[u]){
            has[v]=true;
            ans[v]=z[i]-ans[u];
        }
        else if(has[v]){
            has[u]=true;
            ans[u]=z[i]-ans[v];
        }
        if(mp.count(P(u,v)) && mp[P(u,v)]!=z[i]){
            ok=0;
        }
        mp[P(u,v)]=mp[P(v,u)]=z[i];
    }
    if(!ok)return 0;
    rep(i,1,m){
        if(x[i]==y[i])continue;
        e[x[i]].pb(P(y[i],z[i]));
        e[y[i]].pb(P(x[i],z[i]));
    }
    // rep(i,1,n){
    //     if(!vis[i] && has[i]){
    //         if(!dfs(i))return 0;//自环的
    //     }
    // }
    rep(i,1,n){
        if(!vis[i]){
            stk.clear();
            dfs2(i,1);
        }
    }
    if(!ok)return 0;
    rep(i,1,n)vis[i]=0;
    rep(i,1,n){
        if(!vis[i] && has[i]){
            if(!dfs(i))return 0;//奇环的
        }
    }
    int res=0;
    rep(i,1,n){
        if(has[i]){
            if(l[i]<=ans[i] && ans[i]<=r[i]){
                res++;
            }
        }
    }
    rep(i,1,n){
        if(!vis[i]){
            add.clear();
            dfs3(i,1,0);//二分图偶环的
            sort(add.begin(),add.end());
            int sz=add.size(),now=0,mx=0;
            for(int j=0;j<sz;){
                int k=j;
                while(k+1<sz && add[k+1].fi==add[j].fi){
                    k++;
                }
                //printf("j:%d k:%d\n",j,k);
                rep(x,j,k){
                    //printf("add:(%d,%d)\n",add[x].fi,add[x].se);
                    now+=add[x].se;
                }
                mx=max(mx,now);
                j=k+1;
            }
            res+=mx;
        }
    }
    printf("%d\n",res);
    return 1;
}
int main(){
    sci(t);
    while(t--){
        scanf("%d%d",&n,&m);
        stk.clear();
        mp.clear();
        ok=1;
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