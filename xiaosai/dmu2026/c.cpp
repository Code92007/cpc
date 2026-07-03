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
const int N=1e7+5e6+10,mod=998244353;
int t,n,l,r,v,w;
int main(){
    sci(t);
    while(t--){
        sci(n);
        l=r=1;
        w=-1;
        rep(i,1,n){
            sci(v);
            if(i==v)continue;
            if(w==-1)w=i,l=i;
            if(~w && v==w)r=i;
        }
        printf("%d %d\n",l,r);
    }
    return 0;
}