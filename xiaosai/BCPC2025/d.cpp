#include<bits/stdc++.h>
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
const int N=1e5+10,mod=123456789;
int T,n;
vector<int>x;
set<int>q;
void ins(int y){
    if(y<1 || y>n)return;
    q.insert(y);
}
bool ck(int n){
    x.clear();
    for(auto &v:q)x.pb(v);
    int sz=SZ(x);
    vector<bool>ok(n+1,false);
    rep(i,0,sz-1){
        rep(j,i+1,sz-1){
            ok[x[j]-x[i]]=true;
        }
    }
    rep(i,1,n-1){
        if(!ok[i])return false;
    }
    return SZ(ok)==n-1 && SZ(q)<2048;
    // printf("szok:%d\n",SZ(ok));
    // printf("szq:%d\n",SZ(q));
}
void out(){
    printf("%d\n",SZ(q));
    for(auto &v:q){
        printf("%d ",v);
    }
    puts("");
}
int main(){
    sci(T);
    while(T--){
        sci(n);
        int j=sqrt(n),up=min(n,j+2);
        for(int v=j;v<=up;++v){
            q.clear();
            for(int i=n;i>=v;i-=v){
                q.insert(i);
            }
            for(int i=1;i<=v;i++){
                q.insert(i);
            }
            ck(n);
            //printf("n:%d j:%d SZ(ok):%d szq:%d\n",n,j,SZ(ok),SZ(q));
            //if(ck())break;
        }
        // while(*q.rbegin()<n){
        //     int x=*q.rbegin();
        //     q.insert(x+1);
        // }
        //assert(SZ(q)<2048);
        //if(!ck())printf("n:%d\n",n);
        out();
    }
    return 0;
}
/*
1 100
1 2 98 100 =(1,2,96,97,98,99)
1 2 5 94 98 100=(1,2,3,4,6,89,92,93,95,96,97,98,99)
+99 -98 +96 -93
*/