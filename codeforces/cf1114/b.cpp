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
int t,n,pre[N],suf[N];
char s[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        s[0]='#';
        rep(i,1,n){
            pre[i]=pre[i-1]+(s[i]!=s[i-1]);
        }
        s[n+1]='#';
        per(i,n,1){
            suf[i]=suf[i+1]+(s[i]!=s[i+1]);
        }
        int ans=n;
        rep(i,2,n-1){
            int w=pre[i-1]+suf[i+1];
            if(s[i-1]==s[i+1])w--;
            ans=min(ans,w);
        }
        pte(ans);
    }
    return 0;
}