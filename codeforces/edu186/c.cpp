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
const int N=5e3+10;
int t,n,a[N],b[N],c[N],d[N],e[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
        }
        rep(i,1,n){
            sci(b[i]);
        }
        rep(i,1,n){
            sci(c[i]);
        }
        rep(i,0,n-1)d[i]=e[i]=0;
        rep(i,1,n){
            rep(j,1,n){
                if(a[i]<b[j]){
                    d[(j-i+n)%n]++;
                }
                if(b[i]<c[j]){
                    e[(j-i+n)%n]++;
                }
            }
        }
        int cnt1=0,cnt2=0;
        rep(i,0,n-1){
            //printf("i:%d d:%d e:%d\n",i,d[i],e[i]);
            if(d[i]==n)cnt1++;
            if(e[i]==n)cnt2++;
        }
        printf("%lld\n",1ll*cnt1*cnt2*n);
    }
    return 0;
}