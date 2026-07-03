//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
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
const int N=305,M=30;
typedef array<int,6> A;
struct node{
    int x,y,id;
    A a;
    void read(){
        rep(i,0,5){
            sci(a[i]);
        }
    }
}s,e;
int t,n,m,col,c;
int dis[N][N][M];
int vis[N][N][M];
map<A,int>id;
A to[M];
queue<A>p;
queue<node>q;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},dz[4][M];
int dir[4][6]={
    {4,0,2,3,5,1},
    {1,5,2,3,0,4},
    {3,1,0,5,4,2},
    {2,1,5,0,4,3}
};
node trans(node a,int d){
    node b=a;
    b.x=a.x+dx[d];
    b.y=a.y+dy[d];
    rep(i,0,5){
        b.a[i]=a.a[dir[d][i]];
    }
    b.id=dz[d][a.id];
    return b;
}
void debg(node a){
    printf("x:%d y:%d (上:%d,前:%d,右:%d,左:%d,后:%d,下:%d) id:%d\n",a.x,a.y,a.a[0],a.a[1],a.a[2],a.a[3],a.a[4],a.a[5],a.id);
    //printf("step:%d\n",dis[a.x][a.y][a.id]);
}
bool ok(node y){
    return 1<=y.x && y.x<=n && 1<=y.y && y.y<=m;
}
void init(){
    A x;
    rep(i,0,5)x[i]=i;
    id[x]=0;
    to[0]=x;
    p.push(x);
    node y;
    y.x=y.y=0;
    //puts("gg");
    while(!p.empty()){
        A x=p.front();p.pop();
        int w=id[x];
        y.a=x;y.id=w;
        //printf("w:%d\n",w);
        //debg(y);
        rep(i,0,3){
            node z=trans(y,i);
            if(!id.count(z.a)){
                id[z.a]=++c;
                to[c]=z.a;
                p.push(z.a);
                dz[i][w]=c;
            }
        }
    }
}
int bfs(){
    while(!q.empty())q.pop();
    s.id=0;
    q.push(s);
    dis[s.x][s.y][0]=0;
    while(!q.empty()){
        node x=q.front();q.pop();
        //debg(x);
        if(vis[x.x][x.y][x.id])continue;
        vis[x.x][x.y][x.id]=1;
        if(x.x==e.x && x.y==e.y && x.a[5]==col){
            return dis[x.x][x.y][x.id];
        }
        rep(i,0,3){
            node y=trans(x,i);
            //printf("i:%d\n",i);
            //debg(y);
            if(!ok(y))continue;
            dis[y.x][y.y][y.id]=dis[x.x][x.y][x.id]+1;
            q.push(y);
        }
    }
    return -1;
}
int main(){
    init();
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,n){
            rep(j,1,m){
                rep(k,0,23){
                    dis[i][j][k]=0;
                    vis[i][j][k]=0;
                }
                // dis[i][j].clear();
                // vis[i][j].clear();
            }
        }
        s.read();
        sci(s.x),sci(s.y);
        sci(e.x),sci(e.y);
        sci(col);
        pte(bfs());
    }
    return 0;
}
/*
1
2 2
1 2 3 4 5 6
1 1 2 2 2
*/