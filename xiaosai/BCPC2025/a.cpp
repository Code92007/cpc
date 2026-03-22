#include<bits/stdc++.h>
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
int n,a,b,c,d,e,f,x,y,z,T,ans;
bool in(int x,int y,int z){
    bool f=x>a || (x==a && y>b) || (x==a && y==b && z>=c);
    bool g=x<d || (x==d && y<e) || (x==d && y==e && z<=f);
    return f&&g;
}
int main(){
    sci(n);
    scanf("%d-%d-%d %d-%d-%d",&a,&b,&c,&d,&e,&f);
    rep(i,1,n){
        scanf("%d-%d-%d:%d",&x,&y,&z,&T);
        if(in(x,y,z))ans+=T;
    }   
    pte(ans);
    return 0;
}