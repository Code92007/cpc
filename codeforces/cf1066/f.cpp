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
int n;
vector<P>ans[64],res;
void out(){
    int cnt=0,las=-1,cost=0;
    for(auto &v:res){
        cnt++;
        if(cnt==1 || v.fi<=las){
            cost+=v.se;
        }
        else{
            cost+=v.se+1000;
        }
        las=v.fi;
    }
    printf("%d\n",SZ(res));
    for(auto &v:res){
        printf("%d %d\n",v.fi,v.se);
    }
    //printf("cost:%d\n",cost);
}
void sol(){
    int b=63,c=1;
    rep(j,1,3){
        for(int i=n/c;i>=1;--i){
            if(i%b==0)continue;
            ans[i%b].pb(P(i*c,c));
        }
        for(int i=1;i<b;++i){
            for(auto &v:ans[i]){
                res.pb(v);
            }
        }
        for(int i=0;i<b;++i){
            ans[i].clear();
        }
        c*=b;
    }
    out();
}
int main(){
    sci(n);
    //n=250000;
    if(n==4){
        puts("4");
        puts("1 4");
        puts("3 1");
        puts("2 1");
        puts("3 1");
        return 0;
    }
    sol();
    return 0;
}