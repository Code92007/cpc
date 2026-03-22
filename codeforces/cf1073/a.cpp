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
const int N=105;
int t,n,a[N],b[N],id[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
            id[i]=i;
            if(i&1)b[i]=1;
            else b[i]=0;
        }
        sort(id+1,id+n+1,[&](int x,int y){
            return a[x]<a[y];
        });
        bool ok=1;
        rep(i,2,n){
            int pre=id[i-1],now=id[i];
            if(b[pre]==b[now])ok=0;
        }
        puts(ok?"YES":"NO");
    }
    return 0;
}