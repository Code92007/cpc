#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<set>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
typedef pair<int,int> P;
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
const int N=2e5+10;
int t,n,k,u,v,cnt[N],dep[N],ans,par[N],id[N];
vector<int>e[N],in[N];
void dfs(int u,int fa,int d){
    dep[u]=d;
    par[u]=fa;
    cnt[d]++;
    in[d].pb(u);
    ans=max(ans,cnt[d]);
    int son=0;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u,d+1);
        son++;
    }
    ans=max(ans,son+1);
    if(u!=1){
        e[u].erase(find(e[u].begin(),e[u].end(),fa));
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        ans=0;
        rep(i,0,n){
            in[i].clear();
            e[i].clear();
            cnt[i]=0;
        }
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(1,0,0);
        vector<vector<int> >res(ans,vector<int>());
        per(i,n,0){
            vector<int>p,q;
            for(auto &v:in[i]){
                int sz=SZ(e[v]);
                if(sz>=1){
                    p.pb(v);
                }
                else{
                    q.pb(v);
                }
            }
            if(SZ(p)>1){
                int sz=SZ(p);
                rep(j,0,sz-1){
                    int v=p[j],nex=p[(j+1)%sz],nexson=e[nex][0],pos=id[nexson];
                    id[v]=pos;
                    res[pos].pb(v);
                }
            }
            else if(SZ(p)==1){
                int v=p[0];
                rep(j,0,ans-1){
                    if(res[j].empty() || par[res[j].back()]!=v){
                        id[v]=j;
                        res[j].pb(v);
                        break;
                    }
                }
            }
            int c=0;
            for(auto &v:q){
                while(!res[c].empty() && dep[res[c].back()]==dep[v]){
                    c++;
                }
                id[v]=c;
                res[c].pb(v);
            }
        }
        printf("%d\n",ans);
        for(auto &v:res){
            printf("%d",SZ(v));
            for(auto &x:v){
                printf(" %d",x);
            }
            puts("");
        }
    }
    return 0;
}