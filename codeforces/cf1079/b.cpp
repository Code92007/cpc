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
int t,n,p[N],a[N];
vector<int>b;
bool sol(){
    int x=1;
    for(auto &v:b){
        while(x<=n && p[x]!=v)x++;
        if(x>n)return 0;
        x++;
    }
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(p[i]);
        }
        rep(i,1,n){
            sci(a[i]);
        }
        b.clear();
        for(int i=1;i<=n;){
            int j=i;
            while(j+1<=n && a[j+1]==a[i])j++;
            b.pb(a[i]);
            i=j+1;
        }
        puts(sol()?"YES":"NO");
    }
    return 0;
}