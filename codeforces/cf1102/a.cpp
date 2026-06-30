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
typedef pair<ll,int> P;
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
const int N=110;
int t,n,a[N],b[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
        }
        sort(a+1,a+n+1,greater<int>());
        b[1]=a[1];b[2]=a[2];
        rep(i,3,n){
            b[i]=b[i-2]%b[i-1];
            if(b[i]==0)break;
        }
        bool ok=1;
        rep(i,1,n){
            if(a[i]!=b[i])ok=0;
        }
        if(!ok)puts("-1");
        else printf("%d %d\n",a[1],a[2]);
    }
    return 0;
}