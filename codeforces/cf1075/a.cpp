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
const int N=1e3+10;
int t,n,h,w,a[N];
int main(){
    sci(t);
    while(t--){
        sci(n);sci(h);sci(w);
        rep(i,1,n)sci(a[i]);
        sort(a,a+n+1);
        if(n&1)n--;
        if(h>w)swap(h,w);
        int c1=0,c2=0;
        rep(i,1,n){
            if(a[i]<=h)c1++;
            else if(a[i]<=w)c2++;
        }
        int w=min(c1,c2);
        c1-=w;c2-=w;
        w+=c1/2;
        pte(w);
    }
    return 0;
}