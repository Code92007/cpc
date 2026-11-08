//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
const int N=(5e5+10)*3;
int t,n,par[N],r[N],c[N];
int x[N],cnt,y[N],tot;
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
void mer(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    if(x>y)swap(x,y);
    par[x]=y;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        cnt=tot=0;
        int m=n+1;
        rep(i,1,m){
            sci(r[i]),sci(c[i]);
            x[cnt++]=r[i];
            y[tot++]=c[i];
        }
        sort(x,x+cnt);
        sort(y,y+tot);
        cnt=unique(x,x+cnt)-x;
        tot=unique(y,y+tot)-y;
        int mxr=0,mxc=0,w=cnt+tot+m;
        rep(i,0,w)par[i]=i;
        rep(i,1,m){
            r[i]=lower_bound(x,x+cnt,r[i])-x;//[0,cnt)
            c[i]=lower_bound(y,y+tot,c[i])-y;//[cnt+0,cnt+tot)
            c[i]+=cnt;
            int id=cnt+tot+i;
            mer(id,r[i]);
            mer(id,c[i]);
        }
        //n+1个块答案是2*n 每少一个块答案-1
        //一个块答案是n 每多一个块答案+1
        int blk=0;
        rep(i,1,m){
            int id=cnt+tot+i;
            if(find(id)==id)blk++;
        }
        pte(n-1+blk);
    }
    return 0; 
}