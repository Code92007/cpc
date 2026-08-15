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
const int N=2e5+10;
int t,n,c;
ll a[N],b[N],x[N];
map<ll,ll>mp,to;
bool sol(){
    ll sum=0;
    if(x[0])return 0;
    rep(i,0,c-1){
        if(i+1<c){
            int cnt=mp[x[i]];
            ll delta=x[i+1]-x[i];
            if(delta%cnt)return 0;
            to[x[i]]=delta/cnt;
        }
        else{
            if(i==0)to[x[i]]=1;
            else to[x[i]]=to[x[i-1]]+1;
        }
        if(i){
            if(to[x[i]]<=to[x[i-1]])return 0;
        }
    }
    rep(i,1,n){
        printf("%lld%c",to[b[i]]," \n"[i==n]);
    }
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        mp.clear();
        c=0;
        rep(i,1,n){
            scanf("%lld",&b[i]);
            mp[b[i]]++;
            x[c++]=b[i];
        }
        sort(x,x+c);
        c=unique(x,x+c)-x;
        if(!sol())puts("-1");
    }
    return 0;
}