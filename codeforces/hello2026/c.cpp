#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
#define ull unsigned long long
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
int t,n,m,k;
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m),sci(k);
        int res=1;
        rep(i,1,n){
            if(i==k)continue;
            int x;
            if(i<k)x=k-i;
            else x=i-k;
            int cost=2*x-1;
            if(cost<=m){
                int ans=x+1;
                int left=m-cost,add;
                if(left<=x)add=left;
                else add=max(0,(left-x)/2)+x;
                if(i<k)add=min(add,n-k);
                else add=min(add,k-1);
                ans=max(ans,x+1+add);
                res=max(res,ans);
                //printf("i:%d k:%d x:%d left:%d ans:%d\n",i,k,x,left,ans);
            }
        }
        pte(res);
    }
    return 0;
}
/*
*/