//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
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
const int N=1e5+10,INF=1e9;
int t,n,q,x,a[N];
map<int,bool>mp;
vector<int>now;
int main(){
    sci(t);
    while(t--){
        sci(n),sci(q);
        rep(i,1,n){
            sci(a[i]);
        }
        mp.clear();
        now.clear();
        rep(i,1,n){
            if(a[i]==1){
                mp[1]=true;
                continue;
            }
            now.pb(a[i]);
        }
        n=now.size();
        rep(i,1,n)a[i]=now[i-1];
        rep(i,1,n){
            int now=1;
            rep(j,i,n){
                if(1ll*now*a[j]>INF)break;
                now*=a[j];
                mp[now]=true;
            }
        }
        while(q--){
            sci(x);
            puts(mp.count(x)?"YES":"NO");
        }
    }
}

/*
黑1+3x 白x
多2x+1
*/