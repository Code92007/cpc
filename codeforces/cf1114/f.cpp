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
int t,n,a[N],b[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        int xo=0,ox=0;
        rep(i,1,n){
            sci(a[i]);
            xo^=a[i];
        }
        rep(i,1,n){
            sci(b[i]);
            ox^=b[i];
        }
        rep(i,1,n){
            a[i]=xo^a[i];
            b[i]=ox^b[i];
        }
        a[++n]=xo;
        b[n]=ox;
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        bool ok=1;
        rep(i,1,n){
            //printf("i:%d a:%d b:%d\n",i,a[i],b[i]);
            ok&=(a[i]==b[i]);
        }
        puts(ok?"YES":"NO");
    }
    return 0;
}