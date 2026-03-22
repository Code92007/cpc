//#include<bits/stdc++.h>
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
const int N=1e5+10;
int n,s,sx,sy;
P a[N];
struct node{
    int x,y,ax,ay,id;
    node(int xx,int yy,int aax,int aay,int aid):x(xx),y(yy),ax(aax),ay(aay),id(aid){}
},now;
bool operator<(node a,node b){
    if(a.ax!=b.bx)return a.ax<b.ax;
    return a.ay<b.ay;
}
priority_queue<node>q;
int main(){
    sci(n),sci(s);
    rep(i,1,n){
        int x,y,u,v;
        scanf("%d%d%d%d",&x,&y,&u,&v);
        x-=u,y-=v;
        a[i]=P(x,y);
        if(i==s){
            sx=x,sy=y;
            continue;
        }
        q.push(node(x,y,abs(x),abs(y),i));
    }
    while(!q.empty()){
        node x=q.top();q.pop();
        sx=2ll*x.x-sx,sy=2ll*x.y-sy,s=x.id;
        if(sx==0 )
    }
    return 0;
}
/*
4 0
2 2
2 -2
*/