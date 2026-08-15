//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
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
using namespace std;
int t;
ll k;
ll sol(){
    rep(i,1,100){
        ll x=1ll*i*k;
        int one=0;
        for(ll y=x;y;y=y/10){
            ll z=y%10;
            if(z==0)one++;
            else one=0;
            if(one==2)return x;
        }
    }
    return 100ll*k;
}
int main(){
    sci(t);
    while(t--){
        scanf("%lld",&k);
        printf("%lld\n",sol());
    }
    return 0;
}