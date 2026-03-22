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
typedef pair<int,int> P;
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
const int N=1e5+10,mod=1e9+7;
int t,a,b,k,inv[N];
int C(int n,int m){
    int res=1;
    rep(i,1,m){
        res=1ll*res*(n-i+1)%mod*inv[i]%mod;
    }
    return res;
}
int main(){
    inv[0]=inv[1]=1;
    rep(i,2,100000){
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    sci(t);
    while(t--){
        sci(a),sci(b),sci(k);
        int m=(1ll*(a-1)*k+1)%mod;
        //(b-1)*C(m,a)*k+1
        int res=(1ll*C(m,a)*k%mod*(b-1)%mod+1)%mod;
        printf("%d %d\n",m,res);
    }
    return 0;
}