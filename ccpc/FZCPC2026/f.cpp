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
const int N=1e5+10,M=2e5+10,K=20;
int t,s,k,n,x[N],y[N];
ll a[M],cyc,nex[M][K];
bool ok(ll v){
    int now=1;
    int m=2*n;
    rep(i,1,m){
        while(now<=m && a[now]<a[i]+v){
            now++;
        }
        nex[i][0]=now;
    }
    nex[m+1][0]=m+1;
    rep(j,1,18){
        rep(i,1,m+1){
            nex[i][j]=nex[nex[i][j-1]][j-1];
        }
    }
    rep(i,1,n){
        int p=i;
        per(j,18,0){
            if(k>>j&1)p=nex[p][j];
        }
        //printf("v:%lld i:%d p:%d\n",v,i,p);
        if(p>i+n)continue;
        return 1;
    }
    return 0;
}
int main(){
    sci(t);
    while(t--){
        sci(s),sci(k),sci(n);
        rep(i,1,n){
            sci(x[i]),sci(y[i]);
            if(x[i]==0)a[i]=y[i];
            else if(y[i]==s)a[i]=s+x[i];
            else if(x[i]==s)a[i]=3*s-y[i];
            else a[i]=4*s-x[i];
            //printf("i:%d ai:%lld\n",i,a[i]);
        }
        sort(a+1,a+n+1);
        cyc=4ll*s;
        rep(i,1,n){
            a[i+n]=a[i]+cyc;
        }
        ll l=0,r=cyc;
        while(l<=r){
            ll mid=(l+r)/2;
            if(ok(mid))l=mid+1;
            else r=mid-1;
        }
        printf("%lld\n",r);
    }
    return 0;
}