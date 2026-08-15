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
typedef pair<ll,ll> P;
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
const int N=805;
int t,n,r,c;
char s[N][N],q[10];
void op(int sx,int sy,int tx,int ty){
    printf("%d %d %d %d\n",sx+1,sy+1,tx+1,ty+1);
}
void out(int x,int y){
    printf("%d %d\n",x+1,y+1);
}
void sol1(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,0,n-1){
            scanf("%s",s[i]);
        }
        sci(r),sci(c);
        r--,c--;
        int w=0,si=0,sj=0;
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(s[i][j]=='#'){
                    si=(si+i)%n;
                    sj=(sj+j)%n;
                    w++;
                }
            }
        }
        int dx=(1ll*r*w%n-si+n)%n,dy=(1ll*c*w%n-sj+n)%n;
        if(!dx && !dy){
            op(r,c,r,c);
            continue;
        }
        bool ok=0;
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(ok)break;
                if(s[i][j]=='#'){
                    int ni=(i+dx)%n,nj=(j+dy)%n;
                    if(s[ni][nj]=='#')continue;
                    op(i,j,ni,nj);
                    ok=1;
                }
            }
        }
    }
}
void sol2(){
    sci(t);
    while(t--){
        sci(n);
        int w=0,si=0,sj=0;
        rep(i,0,n-1){
            scanf("%s",s[i]);
            rep(j,0,n-1){
                if(s[i][j]=='#'){
                    si=(si+i)%n;
                    sj=(sj+j)%n;
                    w++;
                }
            }
        }
        int inv;
        rep(i,0,n-1){
            if(1ll*w*i%n==1){
                inv=i;
                break;
            }
        }
        si=1ll*si*inv%n;
        sj=1ll*sj*inv%n;
        out(si,sj);
    }
}
int main(){
    scanf("%s",q);
    if(q[0]=='f')sol1();
    else sol2();
    return 0;
}
//(rx,ry)
//sum(x,y)/w=(px,py)
//(px,py)->(rx,ry)
//(deltax,deltay)=(rx,ry)*w-sum(x,y)