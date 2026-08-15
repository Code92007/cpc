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
const int N=2e5+10,INF=0x3f3f3f3f;
int t,n,a[N];
priority_queue<int>q;
bool ok(int x){
    while(!q.empty())q.pop();
    rep(i,1,n){
        q.push(a[i]);
    }
    x--;
    while(!q.empty()){
        int w=q.top();
        //printf("w:%d x:%d\n",w,x);
        q.pop();
        if(x<0)return 0;
        if(x>=31){
            x--;
            continue;
        }
        int v=1<<x;
        //printf("w:%d v:%d\n",w,v);
        x--;
        if(w<=v)continue;
        w-=v;
        q.push(w);
    }
    return 1;
}
int sol(){
    int l=1,r=n+30;
    while(l<=r){
        int mid=(l+r)/2;
        if(ok(mid))r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
        }
        printf("%d\n",sol());
    }
    return 0;
}
//x/2 (x+1+2+4)/8 x<y+1 