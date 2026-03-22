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
typedef array<int,3> A;
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
const int N=5e5+10;
int t,n,a[N];
ll sum[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        if(n==1){
            puts("-1");
            continue;
        }
        rep(i,1,n){
            a[i]=i;
            sum[i]=sum[i-1]+a[i];
        }
        bool ok=1;
        rep(i,1,n){
            ll x=sqrt(sum[i]);
            //printf("i:%d x:%lld sum:%lld\n",i,x,sum[i]);
            if(1ll*x*x==sum[i]){
                if(i==n)ok=0;
                else{
                    swap(a[i],a[i+1]);
                    sum[i]=sum[i]+a[i]-a[i+1];
                }
            }
        }
        if(!ok)puts("-1");
        else{
            rep(i,1,n){
                printf("%d%c",a[i]," \n"[i==n]);
            }
        }
    }
    return 0;
}