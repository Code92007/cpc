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
const int N=1e5+10;
int t,n,a[N],b[N],c[N],id[N];
ll x;
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%lld",&x);
        rep(i,1,n){
            sci(a[i]),sci(b[i]),sci(c[i]);
            id[i]=i;
        }
        sort(id+1,id+n+1,[&](int x,int y){
            return 1ll*a[x]*b[x]-c[x]>1ll*a[y]*b[y]-c[y];
        });
        ll sum=0;
        rep(i,1,n){
            sum+=1ll*(b[i]-1)*a[i];
        }
        if(sum>=x){
            puts("0");
        }
        else{
            int p=id[1];
            ll w=1ll*a[p]*b[p]-c[p];
            if(w<=0)puts("-1");
            else ptlle((x-sum+w-1)/w);
        }
    }
    return 0;
}