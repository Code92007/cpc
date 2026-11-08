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
const int N=3e5+10;
int t,n,x,a[N];
vector<int>fac[N];
int main(){
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            fac[j].pb(i);
        }
    }
    sci(t);
    while(t--){
        sci(n);sci(x);
        rep(i,1,n){
            sci(a[i]);
        }
        ll ans=0;
        for(auto &v:fac[x]){
            ll tmp=0;
            rep(i,1,n){
                if(a[i]%v==0){
                    tmp+=a[i];
                }
            }
            ans=max(ans,tmp);
        }
        ptlle(ans);
    }
    return 0;
}