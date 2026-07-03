//#include<bits/stdc++.h>
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
typedef pair<int,int> P;
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
const int N=1e6+10;
int T,n,m,a[N],now,cnt[N];
int main(){
    sci(T);
    while(T--){
        sci(n),sci(m);
        rep(i,1,n)sci(a[i]);
        if(m>n){
            puts("-1");
            continue;
        }
        rep(i,1,m)cnt[i]=0;
        now=0;
        int l=1,r=0,ans=n+1;
        while(l<=n){
            while(now<m && r<n){
                ++r;
                if(a[r]<=m){
                    cnt[a[r]]++;
                    if(cnt[a[r]]==1)now++;
                }
            }
            if(now<m)break;
            ans=min(ans,r-l+1);
            if(a[l]<=m){
                cnt[a[l]]--;
                if(cnt[a[l]]==0)now--;
            }
            l++;
        }
        if(ans>n)puts("-1");
        else pte(ans-m);
    }
    return 0;
}
/*
ba ab

cdaba dcaba
cdabba dc
cd abbadc
*/