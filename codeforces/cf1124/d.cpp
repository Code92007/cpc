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
const int N=2e5+10;
int t,n,a[N],p;
vector<int>x,y={1,2,4,7,8,11,13,14};
map<int,int>q;
int main(){
    for(int a:{0,3}){
        for(int b:{0,5}){
            for(int c:{0,12}){
                x.pb(a^b^c);
            }
        }
    }
    sort(x.begin(),x.end());
    for(auto &v:x){
        printf("%5d",v);
    }
    puts("");
    for(auto &v:y)q[v]=1;
    rep(i,0,15){
        if(q.count(i))continue;
        printf("%5d: ",i);
        for(auto &v:x){
            printf("%5d",(v^i)%3);
        }
        puts("");
    }
    return 0;
}