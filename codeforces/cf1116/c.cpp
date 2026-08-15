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
const int N=1e5+10,M=2e5+10,mod=998244353;
int t,n,k,a[2];
char s[M];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        scanf("%s",s+1);
        int m=2*n;
        a[0]=a[1]=0;
        rep(i,1,m){
            int nex=(i==m?1:i+1);
            if(s[i]=='1'){
                if(s[nex]=='0')a[nex%2]++;
                else a[i%2]++;
            }
        }
        printf("%d %d\n",a[0],a[1]);
    }
    return 0;
}