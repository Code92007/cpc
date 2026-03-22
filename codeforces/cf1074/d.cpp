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
const int N=2e5+10;
int t,n,m,h,b[N],c[N],las[N],boom,stamp[N];
ll a[N],d[N];
int main(){
    sci(t);
    while(t--){
        sci(n);sci(m);sci(h);
        rep(i,1,n)sci(a[i]),d[i]=a[i],las[i]=-1,stamp[i]=0;
        boom=0;
        rep(i,1,m){
            sci(b[i]),sci(c[i]);
            if(las[b[i]]>0){
                if(boom>0){
                    if(las[b[i]]>=boom)a[b[i]]+=c[i];
                    else a[b[i]]=d[b[i]]+c[i];
                }
                else{
                    a[b[i]]+=c[i];
                }
            }
            else{
                a[b[i]]+=c[i];
            }
            stamp[b[i]]=i;
            if(a[b[i]]>h)a[b[i]]=d[b[i]],boom=i;
            las[b[i]]=i;
        }
        // per(i,m,1){
        //     a[b[i]]+=c[i];
        //     if(a[b[i]]>h){
        //         a[b[i]]-=c[i];
        //         break;
        //     }
        // }
        rep(i,1,n){
            if(stamp[i]<boom)a[i]=d[i];
            printf("%lld%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}