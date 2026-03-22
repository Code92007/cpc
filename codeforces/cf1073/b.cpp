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
const int N=105;
int t,n,a[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        int zero=0,one=0;
        rep(i,1,n){
            sci(a[i]);
            zero+=(!a[i]);
            one+=(a[i]==1);
        }
        if(!zero){
            puts("NO");
        }
        else{
            if(zero==1)puts("YES");
            else{
                if(!one)puts("NO");
                else puts("YES");
            }
        }
    }
    return 0;
}