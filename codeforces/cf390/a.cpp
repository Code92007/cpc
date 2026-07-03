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
const int N=105;
int n,a[N],sum;
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        sum+=a[i];
    }
    if(sum){
        puts("YES");
        pte(1);
        printf("%d %d\n",1,n);
        return 0;
    }
    int now=0;
    rep(i,1,n){
        now+=a[i];
        if(now!=sum && now!=0){
            puts("YES");
            pte(2);
            printf("%d %d\n",1,i);
            printf("%d %d\n",i+1,n);
            return 0;
        }
    }
    puts("NO");
    return 0;
}