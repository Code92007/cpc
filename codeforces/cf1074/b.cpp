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
const int N=55;
int t,n,a[N],b[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
        }
        int res=0;
        rep(i,1,n){
            rep(j,1,n){
                rep(k,1,n)b[k]=a[k];
                swap(b[i],b[j]);
                int ans=0,mx=0;
                rep(k,1,n){
                    mx=max(mx,b[k]);
                    ans+=mx;
                }
                res=max(res,ans);
            }
        }
        pte(res);
    }
    return 0;
}