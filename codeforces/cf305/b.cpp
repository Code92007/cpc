//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
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
const int N=2e5+10;
int n,a[N],stk[N],c,l[N],r[N],f[N];
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        while(c && a[stk[c]]>=a[i]){
            c--;
        }
        l[i]=(!c?1:stk[c]+1);
        stk[++c]=i;
    }
    c=0;
    per(i,n,1){
        while(c && a[stk[c]]>=a[i]){
            c--;
        }
        r[i]=(!c?n:stk[c]-1);
        stk[++c]=i;
    }
    rep(i,1,n){
        int x=r[i]-l[i]+1;
        //printf("i:%d l:%d r:%d ai:%d\n",i,l[i],r[i],a[i]);
        f[x]=max(f[x],a[i]);
    }
    per(i,n-1,1){
        f[i]=max(f[i],f[i+1]);
    }
    rep(i,1,n){
        printf("%d%c",f[i]," \n"[i==n]);
    }
    return 0;
}