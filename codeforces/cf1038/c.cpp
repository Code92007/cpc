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
const int N=2e5+10;
int t,n;
struct node{
    int x,y,id,w;
}e[N];
bool cmp1(node a,node b){
    return a.x<b.x;
}
bool cmp2(node a,node b){
    return a.y<b.y;
}
vector<int>a[4];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,0,3){
            a[i].clear();
        }
        rep(i,1,n){
            sci(e[i].x),sci(e[i].y);
            e[i].id=i;e[i].w=0;
        }
        sort(e+1,e+n+1,cmp1);
        int p=n/2;
        rep(i,1,p){
            e[i].w+=2;
        }
        sort(e+1,e+n+1,cmp2);
        rep(i,1,p){
            e[i].w++;
        }
        rep(i,1,n){
            a[e[i].w].pb(e[i].id);
        }
        rep(j,0,1){
            int sz=SZ(a[j]);
            rep(i,0,sz-1){
                printf("%d %d\n",a[j][i],a[3-j][i]);
            }
        }
    }
    return 0;
}
/*
(0,0) 3
(0,1) 7
(1,0) 7
(1,1) 3
*/