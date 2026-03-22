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
const int N=110;
int t,n,d[N],a[N];
bool sol(){
    rep(i,1,n){
        if(i==1)a[i]=d[i];
        else{
            a[i]=a[i-1]+d[i];
            //printf("i:%d di:%d ai:%d\n",i,d[i],a[i]);
            if(a[i-1]-d[i]>=0 && d[i])return 0;
        }
    }
    rep(i,1,n){
        printf("%d%c",a[i]," \n"[i==n]);
    }
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n)sci(d[i]);
        if(!sol())puts("-1");
    }
    return 0;
}