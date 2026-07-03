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
const int N=1e5+10;
int n,s[N],a[N],b[N],id[N];
int main(){
    sci(n);
    rep(i,0,n-1){
        sci(s[i]);
        id[i]=i;
    }
    int v=n/3,v2=2*n/3;
    sort(id,id+n,[&](int x,int y){
        return s[x]<s[y];
    });
    rep(i,0,v-1){
        int p=id[i];
        a[p]=i;
        b[p]=s[p]-a[p];
    }
    rep(i,v,v2-1){
        int p=id[i];
        b[p]=i;
        a[p]=s[p]-b[p];
    }
    rep(i,v2,n-1){
        int p=id[i];
        b[p]=n-1-i;
        a[p]=s[p]-b[p];
    }
    puts("YES");
    rep(i,0,n-1){
        printf("%d ",a[i]);
    }
    puts("");
    rep(i,0,n-1){
        printf("%d ",b[i]);
    }
    return 0;
}