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
void sol(){
    int n,m,a,b,x,y,z,v,p;
    a=b=x=y=z=v=p=0;
    sci(z),sci(m);
    a=(z+1)/3,b=(z+9)/10;
    if(z%3)v=z%3;
    else v=3;
    p=m;
    if(p>=v)p-=v,x++;
    x+=p/3;
    y=min(b,m/6);
    printf("%d %d\n",x,y);
}
int main(){
    int t;
    sci(t);
    while(t--){
        sol();
    }
    return 0;
}