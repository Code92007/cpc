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
const int N=1e6+10;
int t,n,m,a[N],b[N];
void sol(int l1,int r1,int l2,int r2){
    if()
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        rep(i,1,n)sci(a[i]);
        rep(j,1,m)sci(b[j]);
        sort(b+1,b+m+1);
        sol(1,m,0,n);
    }
}