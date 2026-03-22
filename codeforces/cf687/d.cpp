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
const int N=1e5+10;
int n,a[N],xo[N];
int cal(int l,int r){
    return xo[r]^xo[l-1];
}
int main(){
    //sci(t);
    int t=1;
    while(t--){
        sci(n);
        rep(i,1,n){
            sci(a[i]);
            xo[i]=xo[i-1]^a[i];
        }
        if(n>=100){//3个最高位相同，100 101 110，此时操作后两个即可
            puts("1");
            continue;
        }
        int ans=n;
        rep(i,1,n-1){
            rep(j,1,i){
                rep(k,i+1,n){
                    if(cal(j,i)>cal(i+1,k)){
                        int len=k-j+1;
                        ans=min(ans,len-2);
                    }
                }
            }
        }
        if(ans==n)puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}