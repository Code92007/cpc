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
int t,n,k,a[N],cnt[N];
int main(){
    sci(t);
    while(t--){
        sci(n);sci(k);
        rep(i,1,n){
            sci(a[i]);
            cnt[a[i]]++;
        }
        int ans=k-1;
        rep(i,0,k-2){
            if(!cnt[i]){
                ans=i;
                break;
            }
        }
        rep(i,1,n){
            cnt[a[i]]--;
        }
        pte(ans);
    }
    return 0;
}
/*
*/