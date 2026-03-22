#include<bits/stdc++.h>
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
const int N=3e3+10;
int t,n,a[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,0,n-1)sci(a[i]);
        sort(a,a+n);
        int c=unique(a,a+n)-a;
        int ans=0,now=0;
        rep(i,0,c-1){
            if(i==0 || a[i]==a[i-1]+1)now++;
            else now=1;
            ans=max(ans,now);
        }
        pte(ans);
    }
    return 0;
}