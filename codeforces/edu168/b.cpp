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
const int N=2e5+10;
int t,n;
char s[2][N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,0,1){
            scanf("%s",s[i]);
        }
        int ans=0;
        rep(i,0,1){
            rep(j,1,n-2){
                if(s[i][j]!='.')continue;
                ans+=(s[i^1][j]=='.' && s[i^1][j-1]=='x' && s[i^1][j+1]=='x' && s[i][j-1]=='.' && s[i][j+1]=='.');
            }
        }
        pte(ans);
    }
    return 0;
}