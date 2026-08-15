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
const int N=1e4+10,M=2e4+10;
char s[N];
int n,ans,no[M],cnt;
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    rep(len,1,n){
        for(int l=1;l+len-1<=n;++l){
            int r=l+len-1;
            if(s[l]!=s[r]){
                no[l+r]++;
            }
            if(no[l+r]<2)cnt++;
        }
    }
    pte(cnt);
    return 0;
}