//#include <bits/stdc++.h>
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
typedef pair<int,int> P;
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=5e3+10,M=8e4+10;
int level[N];
int head[M],cnt;
int t,n,m,c,in[N];
int ss,ee;
P a[N],b[N],match[N];
vector<P>res;
char s[5]="LRUD";
vector<int>row[N],col[N],row2[N],col2[N],f[N];
struct edge{int v,nex;ll w;}e[M];
void init()
{
	cnt=0;
	memset(head,-1,sizeof head);
}
void add(int u,int v,ll w)
{
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].nex=head[u];
	head[u]=cnt++;
}
void add2(int u,int v,ll w,bool op)//是否为有向图 
{
	add(u,v,w);
	add(v,u,op?0:w);
}
bool bfs(int s,int t)
{
	queue<int>q;
	memset(level,0,sizeof level);
	level[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x==t)return 1;
		for(int u=head[x];~u;u=e[u].nex)
		{
			int v=e[u].v;ll w=e[u].w;
			if(!level[v]&&w)
			{
				level[v]=level[x]+1;
				q.push(v);
			}
		}
	}
	return 0;
}
ll dfs(int u,ll maxf,int t)
{
	if(u==t)return maxf;
	ll ret=0;
	for(int i=head[u];~i;i=e[i].nex)
	{
		int v=e[i].v;ll w=e[i].w;
		if(level[u]+1==level[v]&&w)
		{
			ll MIN=min(maxf-ret,w);
			w=dfs(v,MIN,t);
			e[i].w-=w;
			e[i^1].w+=w;
			ret+=w;
			if(ret==maxf)break;
		}
	}
	if(!ret)level[u]=-1;//优化,防止重搜,说明u这一路不可能有流量了 
	return ret;
}
ll Dinic(int s,int t)
{
	ll ans=0;
	while(bfs(s,t))
	ans+=dfs(s,INF,t);
	return ans;
}
void link(int x,int y){
    match[++c]=P(x,y);
}
void add3(int x,int y){
    f[x].pb(y);
    in[y]++;
}
P cal(int x){
    P u=match[x].fi,v=match[x].se;
    if(a[u].fi==b[v].fi){
        if(a[u].se>b[v].se)return P(u,0);
        return P(u,1);
    }
    else{
        if(a[u].fi>b[v].fi)return P(u,2);
        return P(u,3);
    }
}
int main()
{ 
    sci(t);
    while(t--){
        init();
        scanf("%d",&n);
        ss=0,ee=2*n+1;
        c=0;
        rep(i,1,5000){
            row[i].clear();
            row2[i].clear();
            col[i].clear();
            col2[i].clear();
        }
        rep(i,1,n){
            in[i]=0;
            f[i].clear();
            sci(a[i].fi),sci(a[i].se);
            add2(ss,i,1,1);
        }
        rep(i,1,n){
            sci(b[i].fi),sci(b[i].se);
            add2(n+i,ee,1,1);
        }
        rep(i,1,n){
            rep(j,1,n){
                if(a[i].fi==b[j].fi || a[i].se==b[j].se)add2(u,v,1,1);
            }
        }
        ll ans=Dinic(ss,ee);
        if(ans<n)puts("No");
        else{
            rep(u,1,n){
                for(int i=head[u];~i;i=e[i].nex){
                    int v=e[i].v-n;
                    if(v<=n || v>2*n)continue;
                    ll w=e[i].w;
                    if(!w){
                        P x=a[u],y=b[v];
                        if(a[u].fi==b[v].fi){
                            row[a[u].fi].pb(u);
                            row2[b[v].fi].pb(v);
                        }
                        else{
                            col[a[u].se].pb(u);
                            col2[b[v].se].pb(v);
                        }
                        break;
                    }
                }
            }
            rep(i,1,5000){
                if(!row[i].empty()){
                    sort(row[i].begin(),row[i].end(),[&](int x,int y){
                        return a[x].se<a[y].se;
                    });
                    sort(row2[i].begin(),row2[i].end(),[&](int x,int y){
                        return a[x].se<a[y].se;
                    });
                    int sz=row[i].size();
                    rep(j,0,sz-1){
                        link(row[i][j],row2[i][j]);
                    }
                }
                if(!col[i].empty()){
                    sort(col[i].begin(),col[i].end(),[&](int x,int y){
                        return b[x].se<b[y].se;
                    });
                    sort(col2[i].begin(),col2[i].end(),[&](int x,int y){
                        return b[x].se<b[y].se;
                    });
                    int sz=col[i].size();
                    rep(j,0,sz-1){
                        link(col[i][j],col2[i][j]);
                    }
                }
            }
            rep(i,1,n){
                P x=match[i];
                int u=x.fi,v=x.se;
                int op=(a[u].fi==b[v].fi?1:2);
                rep(j,1,n){
                    if(i==j)continue;
                    P y=match[j];
                    int u2=y.fi,v2=y.se;
                    if(op==1){
                        if(a[u].fi==b[v2].fi && in(a[u].se,b[v2].se,b[v].se)){
                            add3(j,i);
                        }
                    }
                    else{
                        if(a[u].se==b[v2].se && in(a[u].fi,b[v2].fi,b[v].fi)){
                            add3(j,i);
                        }
                    }
                }
            }
            res.clear();
            queue<int>q;
            rep(i,1,n){
                if(!in[i])q.push(i);
            }
            while(!q.empty()){
                int u=q.front();q.pop();
                res.pb(cal(u));
                for(auto &v:e[u]){
                    if((--in[v])==0){
                        q.push(v);
                    }
                }
            }
            puts("Yes");
            for(auto &v:ans){
                printf("%d %c\n",v.fi,s[v.se]);
            }
        }
    }
	return 0;
}
/*
a b c d
a->c d->b

topo
*/