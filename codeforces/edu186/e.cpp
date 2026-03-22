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
const int N=2e5+10;
struct node{
    int x,y,z;
    void read(){
        sci(x),sci(y),sci(z);
    }
}e[N];
bool operator<(node a,node b){
    return a.z<b.z;
}
bool cmp(node a,node b){
    if(a.z!=b.z)return a.z<b.z;
    return a.x>b.x;
}
int t,n,m,a[N];
multiset<int>q;
ll k;
void sol(){
    sci(n),sci(m);
    scanf("%lld",&k);
    q.clear();
    rep(i,1,m){
        sci(a[i]);
        q.insert(a[i]);
    }
    rep(i,1,n){
        e[i].read();
        k-=e[i].y;
        e[i].z-=e[i].y;
    }
    sort(e+1,e+n+1,cmp);
    int ans=0;
    per(i,n,1){
        if(!q.empty() && q.lower_bound(e[i].x)!=q.end()){
            ans++;
            e[i].z=0;
            int w=*q.lower_bound(e[i].x);
            q.erase(q.find(w));
        }
    }
    rep(i,1,n){
        if(e[i].z==0)continue;
        if(k>=e[i].z)k-=e[i].z,ans++;
    }
    pte(ans);
}
int main(){
    sci(t);
    while(t--){
        sol();
    }
    return 0;
}
/*
nmd 读错题了
*/