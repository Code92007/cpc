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
const int N=2e5+10;
int t,n,a[N],c;
void cal(int l,int r){
    if(l>r)return;
    for(int i=l;i<=r;i+=2){
        ++c;
        a[i]=a[i+1]=c;
    }
}
void sol(){
    if(n&1){
        if(n<=25){
            puts("-1");
            return;
        }
        a[1]=a[10]=a[26]=++c;//9+16=25
        cal(2,9);
        cal(11,22);
        a[23]=a[27]=++c;
        a[24]=a[25]=++c;
        cal(28,n);
    }
    else{
        cal(1,n);
    }
    rep(i,1,n){
        printf("%d%c",a[i]," \n"[i==n]);
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        c=0;
        sol();
    }
    return 0;
}
/*
*/