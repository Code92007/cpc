//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=2e5+10;
int n,a[N],ans;
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
    }
    rep(i,1,n){
        ll sum=0;
        rep(j,i+1,n-1){
            sum+=a[j];
            if(sum==(a[i]^a[j+1])){
                if(a[i]>=a[j+1])ans++;//相同认为左边大，只从两个数更大的那个数统计区间贡献
            }
            if(sum>2*a[i])break;
        }
    }
    per(i,n,1){
        ll sum=0;
        per(j,i-1,2){
            sum+=a[j];
            if(sum==(a[i]^a[j-1])){
                if(a[i]>a[j-1])ans++;
            }
            if(sum>2*a[i])break;
        }
    }
    pte(ans);
    return 0;
}