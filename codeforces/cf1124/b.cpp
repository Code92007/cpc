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
const int N=1e3+10;
int t,n,a[N];
map<int,int>q;
int f(int x){
    int ans=0;
    //printf("x:%d\n",x);
    for(;x;x/=10){
        int y=x%10;
        ans+=y*y;
    }
    //printf("x:%d ans:%d\n",x,ans);
    return ans;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        q.clear();
        rep(i,1,n){
            sci(a[i]);
            rep(j,1,100){
                int nex=f(a[i]);
                a[i]=nex;
            }
            q[a[i]]++;
        }
        ll ans=0;
        for(auto &v:q){
            ll w=v.se;
            ans+=1ll*w*(w-1)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}