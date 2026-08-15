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
const int N=1e3+5;
int n,m,cnt[N][26];
char s[N];
int main(){
    sci(n),sci(m);
    rep(j,1,m){
        scanf("%s",s+1);
        rep(i,1,n){
            cnt[i][s[i]-'a']++;
        }
    }
    rep(i,1,n){
        int mx=0,pos=0;
        rep(j,0,25){
            if(mx<cnt[i][j])mx=cnt[i][j],pos=j;
        }
        printf("%c",pos+'a');
    }
    puts("");
    return 0;
}