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
int t,a,b;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
vector<P>all;
set<P>ano;
bool sol(){
    int delta=(max(a,b)-min(a,b))/2;
    if(min(a,b)<delta)return 0;
    all.clear();
    ano.clear();
    int st=2+(a>b);
    for(int ix=2,iy=st,cnt=0;ix<=1000 && iy<=1000 && cnt<delta;cnt++){
        all.pb(P(ix,iy));
        iy+=2;
        if(iy>1000){
            ix+=2;
            iy=st;
        }
    }
    for(auto &v:all){
        for(int i=0;i<4;++i){
            int x=v.fi+dx[i],y=v.se+dy[i];
            while(SZ(ano)-SZ(all)<delta)ano.insert(P(x,y));
        }
    }
    P s=P(1,2);
    if(!all.empty() && all.back()>s)s=all.back();
    if(!ano.empty() && ano.rbegin()>s)s=ano.rbegin();
    s.fi++;
    for(auto &v:ano){
        all.pb(v);
    }
    int sg=1;
    while(SZ(all)<a+b){
        all.pb(P(s.fi,s.se));
        s.se+=sg;
        if(s.se>1000)s.fi++,s.se=1000,sg=-1;
        if(s.se<1)s.fi++,s.se=1,sg=1;
    }
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(a),sci(b);
        if(sol()){
            puts("YES");
            for(auto &x:all)printf("%d %d\n",x.fi,x.se);
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