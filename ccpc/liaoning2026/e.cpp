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
const int N=2e5+10;
int n,a[N],b[N],tmp[N];
ll ans;
void cdq(int l,int r){
    if(l==r){
        b[l]=a[l]+l;
        return;
    }
    int mid=(l+r)/2;
    cdq(l,mid);
    cdq(mid+1,r);
    int x=l,y=mid+1,p=l;
    while(x<=mid && y<=r){
        if(b[x]<=b[y])tmp[p++]=b[x++];
        else ans+=mid-x+1,tmp[p++]=b[y++];
    }
    while(x<=mid)tmp[p++]=b[x++];
    while(y<=r)tmp[p++]=b[y++];
    rep(i,l,r){
        b[i]=tmp[i];
    }
}
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
    }
    cdq(1,n);
    ans%=2;
    puts(ans?"Shion":"Kanon");
    return 0; 
}