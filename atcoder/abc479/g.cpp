//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
const db eps=1e-6;
const int N=2e5+10;
int n,a[N],b[N];
ll ans,ans2;
db res;
vector<P>tmp;
int main(){
    sci(n);
    rep(i,1,n)sci(a[i]);
    rep(i,1,n)sci(b[i]);
    rep(i,1,n){
        ans+=abs(a[i]);
        ans2+=abs(b[i]);
    }
    res=min(ans,ans2);
    ans=ans2=0;
    rep(i,1,n){
        ans+=abs(a[i]-b[i]);
        ans2+=abs(a[i]+b[i]);
    }
    res=min(res,1.*ans);
    res=min(res,1.*ans2);
    ans=ans2=0;
    rep(i,1,n){
        ans+=b[i];
        ans2+=abs(a[i]);
    }
    if(ans2){
        db k=ans/ans2;
        if(eps<fabs(k) && fabs(k)<=1){
            k=1./k;
            db sum=0;
            rep(i,1,n){
                sum+=fabs(b[i]/k-a[i]);
            }
            res=min(res,sum);
        }
    }
    rep(i,1,n)swap(a[i],b[i]);
    ans=ans2=0;
    rep(i,1,n){
        ans+=b[i];
        ans2+=abs(a[i]);
    }
    if(ans2){
        db k=ans/ans2;
        if(eps<fabs(k) && fabs(k)<=1){
            k=1./k;
            db sum=0;
            rep(i,1,n){
                sum+=fabs(b[i]/k-a[i]);
            }
            res=min(res,sum);
        }
    }
    printf("%.6lf\n",res);
    return 0;
}