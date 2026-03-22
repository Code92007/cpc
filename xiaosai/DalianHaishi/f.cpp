//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
#include<unordered_map>
#include<set>
#define ll long long
#define ull unsigned ll
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef double db;
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
using namespace std;
typedef pair<int,int> P;
const int N=1024;
int s;
bool used[N];
//vector<P>ans;
int main(){
    sci(s);
    printf("%d\n",1023);
    rep(i,0,9){
        per(j,1023,1){
            if(j>>i&1 && !used[j]){
                used[j]=1;
                printf("%d %d\n",j,1<<i);
            }
        }
    }
    //printf("%d\n",SZ(ans));
    // for(auto &v:ans){
    //     printf("%d %d\n",v.fi,v.se);
    // }
    return 0;
}