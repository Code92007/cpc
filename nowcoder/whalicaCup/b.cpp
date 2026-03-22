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
int t,n;
vector<int>ans;
void sol(int n){
    rep(i,1,n/2){
        ans.pb(n/2+i);
        ans.pb(i);
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        ans.clear();
        if(n&1)sol(n-1),ans.pb(n);
        else sol(n);
        puts("YES");
        for(auto &v:ans){
            printf("%d ",v);
        }
        puts("");
    }
    return 0;
}