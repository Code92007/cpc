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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=1e5+10;
int n,m,a[N],b[N],c[N],v,now;
ll add,tot;
bool ok=1;
int main(){
    sci(n),sci(m);
    rep(i,1,n)sci(a[i]);
    rep(i,1,n)sci(b[i]);
    rep(i,1,n)sci(c[i]);
    rep(i,1,n){
        sci(v);
        if(!ok)continue;
        if(m-tot>=c[i]){
            tot+=c[i];
            if(v)add+=a[i],now++,add+=b[now];
            else now=0;
        }
        else{
            ok=0;
        }
    }
    printf("%lld\n",add);
    return 0;
}