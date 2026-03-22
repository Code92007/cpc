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
int t,n,k,u,v,dep[N],my[N],ans,mxd,par[N];
vector<int>e[N];
set<int>now[N],in[N],alld,ld,rd;
vector<int>del,tmp;
void dfs(int u,int fa,int d){
    my[u]=d;
    par[u]=fa;
    //printf("u:%d fa:%d d:%d\n",u,fa,d);
    dep[d]++;
    alld.insert(d);
    in[d].insert(u);
    ans=max(ans,dep[d]);
    //if(ans==dep[d])mxd=d;
    mxd=max(mxd,d);
    int cnt=0;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u,d+1);
        now[u].insert(v);
        cnt++;
    }
    ans=max(ans,cnt+1);
}
void choose(int u){
    int fa=par[u],d=my[u];
    if(fa)now[fa].erase(u);
    in[d].erase(u);
    tmp.pb(u);
    if(in[d].empty()){
        del.pb(d);
    }
}
void delet(){
    for(auto &d:del){
        if(ld.count(d))ld.erase(d);
        if(rd.count(d))rd.erase(d);
    }
    del.clear();
    tmp.clear();
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        del.clear();
        ans=0;
        mxd=0;
        alld.clear();
        ld.clear();
        rd.clear();
        rep(i,0,n){
            now[i].clear();
            in[i].clear();
            e[i].clear();
            dep[i]=0;
        }
        rep(i,2,n){
            sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(1,0,0);
        vector<vector<int> >res(ans,vector<int>());
        // for(auto &v:alld){
        //     if(v<mxd)ld.insert(v);
        //     if(v>mxd)rd.insert(v);
        // }
        printf("%d\n",ans);
        rep(i,1,ans){
            delet();
            int las;
            while(in[mxd].empty())mxd--;
            int mid=*in[mxd].begin();
            las=mid;
            choose(las);
                //printf("i:%d las:%d\n",i,las);
                for(auto it=.rbegin();it!=ld.rend();++it){
                    int d=*it;
                    for(auto &z:in[d]){
                        if(z==par[las])continue;
                        //printf("d2:%d z:%d\n",d,z);
                        las=z;
                        choose(z);
                        break;
                    }
                    //printf("d:%d las:%d\n",d,las);
                }
                las=mid;
                for(auto it=alld.begin();it!=rd.end();++it){
                    int d=*it;
                    for(auto &z:in[d]){
                        if(par[z]==las)continue;

                        las=z;
                        choose(z);
                        break;
                    }
                }
            }
            printf("%d",SZ(tmp));
            for(auto &v:tmp){
                printf(" %d",v);
            }
            puts("");
        }
        // pte(ans);
    }
    return 0;
}
/*
*/