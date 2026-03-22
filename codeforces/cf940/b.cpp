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
int t,n,k,a[N];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        rep(i,1,n)a[i]=0;
        rep(i,0,30){
            int v=1<<i;
            if(k>=v)a[1]|=v,k-=v;
        }
        if(n==1)a[1]+=k;
        else a[2]=k;
        rep(i,1,n){
            printf("%d%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}