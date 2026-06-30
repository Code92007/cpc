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
typedef array<ll,3> A;
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
namespace fastIO
{
    static char buf[100000],*h=buf,*d=buf;//缓存开大可减少读入时间，看题目给的空间
    #define gc h==d&&(d=(h=buf)+fread(buf,1,100000,stdin),h==d)?EOF:*h++//不能用fread则换成getchar
    template<typename T>
    inline void read(T&x)
    {
        int f = 1;x = 0;
        register char c(gc);
        while(c>'9'||c<'0'){
            if(c == '-') f = -1;
            c=gc;
        }
        while(c<='9'&&c>='0')x=(x<<1)+(x<<3)+(c^48),c=gc;
        x *= f;
    }
    template<typename T>
    void output(T x)
    {
        if(x<0){putchar('-');x=~(x-1);}
        static int s[20],top=0;
        while(x){s[++top]=x%10;x/=10;}
        if(!top)s[++top]=0;
        while(top)putchar(s[top--]+'0');
    }
}
using namespace fastIO;
const int N=1e5+10,M=2*N;
int t,n,q,dp[M][19],pos;
int dfn[M],tot;//欧拉序 
int dep[M],id[M],lg[M];//各顶点深度
bool ok[N];
map<int,bool>now;
ll ans[N],tmp[N],cnt[N];
vector<int>e[N];
void dfs(int u,int fa,int d){
    id[u]=++tot;
    dep[tot]=d;
	dfn[tot]=u;
    //printf("u:%d id:%d\n",u,id[u]);
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u,d+1);
        dfn[++tot]=u;
		dep[tot]=d;
    }
}
void dfs2(int u,int fa){
    tmp[u]=0;
    cnt[u]=0;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs2(v,u);
        tmp[u]+=tmp[v];
        tmp[u]+=cnt[v];
        cnt[u]+=cnt[v];
    }
    if(ok[u])cnt[u]=1;
}
void ST(){
	for(int i=1;i<=tot;++i)
	dp[i][0]=i;
	for(int len=1;(1<<len)<=tot;++len){
		for(int l=1;l+(1<<len)-1<=tot;++l){
			if(dep[dp[l][len-1]]<dep[dp[l+(1<<(len-1))][len-1]])dp[l][len]=dp[l][len-1];
			else dp[l][len]=dp[l+(1<<(len-1))][len-1];
		}
	}
}
int RMQ(int l,int r){
	int len=lg[r-l+1];
	if(dep[dp[l][len]]<dep[dp[r-(1<<len)+1][len]])return dp[l][len];
	else return dp[r-(1<<len)+1][len];
}
int lca(int u,int v){
	int mn=min(id[u],id[v]);
	int mx=max(id[u],id[v]);
	return dfn[RMQ(mn,mx)];
}
void op(int u,int v){
    tmp[u]-=tmp[v];
    tmp[u]-=cnt[v];
    cnt[u]-=cnt[v];
    cnt[v]+=cnt[u];
    tmp[v]+=cnt[u];
    tmp[v]+=tmp[u];
}
void dfs3(int u,int fa){
    ans[u]=tmp[u];
    for(auto &v:e[u]){
        if(v==fa)continue;
        op(u,v);
        dfs3(v,u);
        op(v,u);
    }
}
int dis(int u,int v){
    //printf("u:%d v:%d idu:%d idv:%d lca:%d\n",u,v,id[u],id[v],lca(u,v));
    int p=id[u],q=id[v],r=id[lca(u,v)];
    //printf("u:%d v:%d p:%d q:%d r:%d depp:%d depq:%d 2*depr:%d\n",u,v,p,q,r,dep[p],dep[q],2*dep[r]);
    return dep[p]+dep[q]-2*dep[r];
    //return dep[u]+dep[v]-dep[lca(u,v)];
}
int main(){
    rep(i,2,M-5)lg[i]=lg[i>>1]+1;
    read(t);
    //sci(t);
    while(t--){
        now.clear();
        read(n);read(q);
        //sci(n),sci(q);
        rep(i,1,n){
            e[i].clear();
            ok[i]=0;
            ans[i]=0;
        }
        tot=1;
        rep(i,1,2*n+1){
            id[i]=dep[i]=dfn[i]=0;
        }
        rep(i,1,n-1){
            int u,v;
            read(u),read(v);
            //sci(u),sci(v);
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(1,0,0);
        ST();
        int cnt=0;
        ll mx=0;
        int pos=1,vv=1;
        while(q--){
            int u,v;
            read(u),read(v);
            //sci(u),sci(v);
            if(u==1){
                cnt++;
                if(now.count(v))now.erase(v);
                else now[v]=true;
                if(cnt==300){
                    vector<int>vis;
                    for(auto &x:now){
                        int w=x.fi;
                        vis.pb(w);
                    }
                    for(auto &v:vis){
                        ok[v]^=1;
                    }
                    dfs2(1,0);
                    dfs3(1,0);
                    cnt=0;
                    now.clear();
                }
            }
            else{
                vv=v;
            }
            //printf("now:%d\n",vv);
            ll res=ans[vv];
            vector<int>vis;
            for(auto &x:now){
                int w=x.fi;
                vis.pb(w);
            }
            for(auto &w:vis){
                if(ok[w]){//sub
                    res-=dis(vv,w);
                }
                else{//add
                    //printf("v:%d w:%d dis:%d\n",vv,w,dis(vv,w));
                    res+=dis(vv,w);
                }
            }
            //printf("%lld\n",res);
            if(res>mx)mx=res,pos=vv;
            else if(res==mx)pos=min(pos,vv);
        }
        printf("%d\n",pos);
    }
    return 0;
}