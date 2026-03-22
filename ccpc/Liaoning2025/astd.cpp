//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define x first
#define y second
typedef pair<int,int> pii;
const int N=5010,M=N*4;
const int gx[]={-1,1,0,0},gy[]={0,0,-1,1};
const char gc[]={'U','D','L','R'};
int n;
pii gull[N],food[N];
int m[N][N];
int gf[N][4];
int match[N];
bool vis[N];
int dir[N];
int h[N],e[M],ne[M],idx;
int deg[N];
int st[N],top;
bool in_st[N];
int seq[N],sidx;
int q[N],hh,tt;

bool hungary(int u)
{
    for(int d=0;d<4;d++)
    {
        int v=gf[u][d];
        if(v && !vis[v])
        {
            vis[v]=true;
            if(!match[v] || hungary(match[v]))
            {
                dir[u]=d,match[v]=u;
                return true;
            }
        }
    }
    return false;
}

void dfs(int u)
{
    vis[u]=in_st[u]=true;
    st[++top]=u;
    for(int i=h[u];i && !sidx;i=ne[i])
    {
        int v=e[i];
        if(!vis[v]) dfs(v);
        else if(in_st[v])
        {
            for(int j=top;st[j]!=v;j--) seq[++sidx]=st[j];
            seq[++sidx]=v;
            reverse(seq+1,seq+sidx+1);
        }
    }
    top--;
    in_st[u]=false;
    return ;
}

void topsort()
{
    for(int u=1;u<=n;u++)
        if(!deg[u])
        {
            cout<<u<<' '<<gc[dir[u]]<<'\n';
            q[++tt]=u;
        }
    while(hh<=tt)
    {
        int u=q[hh];
        hh++;
        for(int i=h[u];i;i=ne[i])
        {
            int v=e[i];
            deg[v]--;
            if(!deg[v])
            {
                cout<<v<<' '<<gc[dir[v]]<<'\n';
                q[++tt]=v;
            }
        }
    }
    return ;
}

inline void solve()
{
    for(int u=1;u<=n;u++) m[gull[u].x][gull[u].y]=m[food[u].x][food[u].y]=0;
    cin>>n;
    hh=1,tt=0;
    for(int u=1;u<=n;u++)
    {
        match[u]=vis[u]=0;
        for(int d=0;d<4;d++) gf[u][d]=0;
    }
    for(int u=1;u<=n;u++)
    {
        cin>>gull[u].x>>gull[u].y;
        m[gull[u].x][gull[u].y]=u;
    }
    for(int u=1;u<=n;u++)
    {
        cin>>food[u].x>>food[u].y;
        m[food[u].x][food[u].y]=u+n;
    }
    for(int u=1;u<=n;u++)
        for(int d=0;d<4;d++)
        {
            int x=gull[u].x+gx[d],y=gull[u].y+gy[d];
            while(1<=m[x][y] && m[x][y]<=n) x+=gx[d],y+=gy[d];
            if(m[x][y]>=1+n) gf[u][d]=m[x][y]-n;
        }
    for(int u=1;u<=n;u++)
    {
        for(int v=1;v<=n;v++) vis[v]=false;
        if(!hungary(u))
        {
            cout<<"No\n";
            return ;
        }
    }
    cout<<"Yes\n";
    do
    {
        idx=sidx=0;
        for(int u=1;u<=n;u++) h[u]=deg[u]=vis[u]=0;
        for(int u=1;u<=n;u++)
        {
            int d=dir[u];
            int x=gull[u].x+gx[d],y=gull[u].y+gy[d];
            while(1<=m[x][y] && m[x][y]<=n)
            {
                int v=m[x][y];
                e[++idx]=v,ne[idx]=h[u],h[u]=idx;
                deg[v]++;
                x+=gx[d],y+=gy[d];
            }
        }
        for(int u=1;u<=n && !sidx;u++)
            if(!vis[u])
                dfs(u);
        dir[seq[0]]=dir[seq[sidx]];
        for(int i=sidx;i>=1;i--) dir[seq[i]]=dir[seq[i-1]];
    }while(sidx);
    topsort();
    return ;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}