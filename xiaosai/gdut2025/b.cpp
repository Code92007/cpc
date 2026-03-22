//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
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
const int N=1000,M=800;
int t,a,b;
int dx[4]={0,-1,1,0},dy[4]={1,0,0,-1};
int dx2[4]={0,2,0,-2},dy2[4]={2,0,-2,0};
vector<P>all;
set<P>ano,used;
bool sol(){
    int w=max(a,b)-min(a,b);
    int delta=w/2;
    if(min(a,b)<delta)return 0;
    all.clear();
    ano.clear();
    used.clear();
    //printf("delta:%d\n",delta);
    int st=2+(a>b),cur=0;
    for(int ix=2,iy=st;SZ(all)<delta;){
        //printf("ix:%d iy:%d\n",ix,iy);
        all.pb(P(ix,iy));
        used.insert(P(ix,iy));
        while(used.count(P(ix+2*dx2[cur],iy+2*dy2[cur])) || ix+dx2[cur]>=M || iy+dy2[cur]>=M || ix+dx2[cur]<=1 || iy+dy2[cur]<=1){
            cur=(cur+1)%4;
        }
        ix+=dx2[cur],iy+=dy2[cur];
        //printf("ix:%d iy:%d\n",ix,iy);
    }
    for(auto &v:all){
        for(int i=0;i<4;++i){
            int x=v.fi+dx[i],y=v.se+dy[i];
            //printf("x:%d y:%d\n",x,y);
            if(SZ(ano)<SZ(all)+w){
                //printf("x2:%d y2:%d ano:%d all:%d\n",x,y,SZ(ano),SZ(all));
                ano.insert(P(x,y));
            }
        }
    }
    int na=a,nb=b;
    if(na>nb)na-=SZ(ano),nb-=SZ(all);
    else nb-=SZ(ano),na-=SZ(all);
    P s=P(1,1);
    if(na==nb){
        if(!all.empty() && all.back()>s)s=all.back();
        if(!ano.empty() && (*ano.rbegin())>s)s=*ano.rbegin();
        s.fi++;
        // int need=a+b-SZ(all);
        // printf("need:%d\n",need);
        // assert(need%2==0);
    }
    else{
        if(na<nb){
            //printf("na:%d nb:%d a:%d b:%d delta:%d ano:%d all:%d w:%d\n",na,nb,a,b,delta,SZ(ano),SZ(all),w);
            //if(na+1!=nb)puts("gg2");
            s.fi++;
        }
        else{
            //printf("na:%d nb:%d a:%d b:%d delta:%d ano:%d all:%d w:%d\n",na,nb,a,b,delta,SZ(ano),SZ(all),w);
            //if(nb+1!=na)puts("gg3");
        }
    }
    for(auto &v:ano){
        all.pb(v);
    }
    int sg=1;
    while(SZ(all)<a+b){
        all.pb(P(s.fi,s.se));
        s.se+=sg;
        if(s.se>N)s.fi++,s.se=N,sg=-1;
        if(s.se<1)s.fi++,s.se=1,sg=1;
    }
    return 1;
}
void check(){
    for(auto &v:all){
        if((v.fi+v.se)%2==1)b--;
        else a--;
        //if(v.se>N || v.fi>N)puts("gg1");
    }
    assert(a==0 && b==0);
    //if(a || b)puts("gg4");
    for(auto &x:all)printf("%d %d\n",x.fi,x.se);
}
int main(){
    sci(t);
    while(t--){
        sci(a),sci(b);
        if(sol()){
            puts("YES");
            check();
        }
        else{
            puts("NO");
        }
    }
}

/*
黑1+3x 白x
多2x+1
*/