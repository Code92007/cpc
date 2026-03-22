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
int t;
ll l,r;
A sol(ll l,ll r){
    if(l==r){
        return A{0,0,1};
    }
    A key=A{l,r},ans;
    ll v=1ll<<(63-__builtin_clzll(l^r));
    ll w=v|(v-1);
    l&=w,r&=w;
    ll lb=v-l,rb=r-v+1;
    if(lb!=rb){
        A b=sol(l,v-1),c=sol(v,r);
        //printf("l:%lld r:%lld x:%lld ",l,r,x);
        //printf("b:{%lld,%lld,%lld} c:{%lld,%lld,%lld}\n",b[0],b[1],b[2],c[0],c[1],c[2]);
        ans=A{max(b[0],c[0]),min(b[1],c[1]),min(b[2],c[2])};
    }
    else{
        A d=sol(l,v-1);
        d[2]*=2;
        ans=d;
    }
    //0010 0011 1000 1001 1010 1011
    //printf("l:%lld r:%lld x:%lld ",l,r,x);
    //printf("ans:(%lld,%lld,%lld)\n",ans[0],ans[1],ans[2]);
    return ans;
}
int main(){
    sci(t);
    while(t--){
        scanf("%lld%lld",&l,&r);
        A ans=sol(l,r);
        printf("%lld\n",1ll*(ans[1]-ans[0]+1)*ans[2]-1);
    }
    return 0;
}
