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
const int N=2e5+10,M=2*N;
int t,n,s1[N],s2[N],one1,zero1,one2,zero2;
ll w2[M],w3[M],w4[M];
char a[N],b[N];
P cal(ll s[],ll w[],int l,int r){
    return P(s[r]-s[l-1],w[r]-w[l-1]);
}
ll sol(){
    one1=one2=zero1=zero2=0;
    sci(n);
    int O=n+1,up=2*n+1;
    rep(i,0,up){
        w2[i]=w3[i]=w4[i]=0;
    }
    scanf("%s%s",a+1,b+1);
    rep(i,1,n){
        int v1=(a[i]=='1'?1:-1);
        s1[i]=s1[i-1]+v1;
        int v2=(b[i]=='1'?1:-1);
        one2+=(b[i]=='1');
        zero2+=(b[i]=='0');
        s2[i]=s2[i-1]+v2;
        w2[s2[i]+O]++;
        w3[s2[i]+O]+=one2;
        w4[s2[i]+O]+=zero2;
    }
    rep(i,1,up){
        w2[i]+=w2[i-1];
        w3[i]+=w3[i-1];
        w4[i]+=w4[i-1];
    }
    ll ans=0;
    rep(i,1,n){
        one1+=(a[i]=='1');
        zero1+=(a[i]=='0');
        auto x=cal(w2,w4,O-s1[i]+1,up);//one-zero>0 zero
        auto y=cal(w2,w3,1,O-s1[i]);//one-zero<=0 one
        ans+=1ll*zero1*x.fi+x.se;
        ans+=1ll*one1*y.fi+y.se;
    }
    return ans;
}
int main(){
    sci(t);
    while(t--){
        ptlle(sol());
    }
    return 0;
}