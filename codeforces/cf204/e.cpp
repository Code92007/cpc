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
const int N=2e3+10;
int n,a[N],ans;
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        a[i]=abs(a[i]);
    }
    rep(i,1,n){
        int left=0,right=0;
        rep(j,1,n){
            if(j==i)continue;
            if(a[j]<a[i]){
                if(j<i)left++;
                else right++;
            }
        }
        ans+=min(left,right);
    }
    printf("%d\n",ans);
    return 0;
}