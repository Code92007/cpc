#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<random>
#include<algorithm>
#include<cmath>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
typedef array<int,3> A;
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
const int N=2e3+10;
int t,n,m,cnt[N][N],tag[N][N];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char dz[5]="UDLR",s[N][N];
vector<P>ask[N][N],dog;
queue<P>q;
P st,ed;
bool ok(int x,int y){
    if(!(x>=1 && x<=n && y>=1 && y<=m))return 0;
    return s[x][y]=='.' || s[x][y]=='S' || s[x][y]=='E';
}
void bfs(P s,int y){
    tag[s.fi][s.se]|=y;
    q.push(s);
    while(!q.empty()){
        P x=q.front();
        q.pop();
        //printf("x.fi:%d x.se:%d y:%d\n",x.fi,x.se,y);
        rep(i,0,3){
            int ni=x.fi+dx[i],nj=x.se+dy[i];
            if(!ok(ni,nj))continue;
            if(cnt[ni][nj]>=1)continue;
            //printf("ni:%d nj:%d\n",ni,nj);
            if(tag[ni][nj]&y)continue;
            tag[ni][nj]|=y;
            q.push(P(ni,nj));
        }
    }
}
P sol(){
    if(tag[ed.fi][ed.se]&1){
        return dog[0];
    }
    for(auto &w:dog){
        int now=0,i=w.fi,j=w.se;
        //printf("i:%d j:%d\n",i,j);
        for(auto &u:ask[i][j]){
            int x=u.fi,y=u.se;
            if(cnt[x][y]>=2){
                now=0;
                continue;
            }
            //printf("x:%d y:%d\n",x,y);
            rep(i,0,3){
                int nx=x+dx[i],ny=y+dy[i];
                if(!ok(nx,ny))continue;
                now|=tag[nx][ny];
                //printf("nx:%d ny:%d tag:%d\n",nx,ny,tag[nx][ny]);
                if(now==3)return w;
            }
        }
    }
    return P(-1,-1);
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,n){
            scanf("%s",s[i]+1);
            rep(j,1,m){
                cnt[i][j]=0;
                tag[i][j]=0;
                ask[i][j].clear();
            }
        }
        rep(i,1,n){
            rep(j,1,m){
                if(s[i][j]=='S')st=P(i,j);
                else if(s[i][j]=='E')ed=P(i,j);
                else if(s[i][j]=='.' || s[i][j]=='#')continue;
                else{
                    int p,ni=i,nj=j;
                    rep(k,0,3){
                        if(s[i][j]==dz[k]){
                            p=k;
                            break;
                        }
                    }
                    dog.pb(P(i,j));
                    s[i][j]='#';
                    ni+=dx[p],nj+=dy[p];
                    //printf("p:%d i:%d j:%d ni:%d nj:%d\n",p,i,j,ni,nj);
                    while(ok(ni,nj)){
                        ask[i][j].pb(P(ni,nj));
                        cnt[ni][nj]++;
                        ni+=dx[p],nj+=dy[p];
                    }
                }
            }
        }
        bfs(st,1);
        bfs(ed,2);
        P x=sol();
        printf("%d %d\n",x.fi,x.se);
        dog.clear();
    }
    return 0;
}
/*
4
7 7
.D....E
...#..L
..#...L
.#.L..D
....#..
#.L....
S...#.L
3 3
..E
R.L
S..
4 4
.D.E
....
.D..
S...
7 5
....E
.....
.R...
.#.#.
...L.
.....
S.U..
*/