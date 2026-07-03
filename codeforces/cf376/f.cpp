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
typedef array<int,3> A;
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
int n,a[N],cnt[N];
ll res;
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        cnt[a[i]]++;
    }
    int w=2e5;
    rep(i,1,w)cnt[i]+=cnt[i-1];
    for(int i=1;i<=w;++i){
        int v=cnt[i]-cnt[i-1];
        if(!v)continue;
        ll ans=i;
        for(int j=i;j<=w;j+=i){
            int sum=(j+i-1>w?n:cnt[j+i-1])-cnt[j-1];
            if(j==i)sum--;
            ans+=1ll*sum*j;
            // if(sum){
            //     printf("i:%d j:%d ans:%lld\n",i,j,ans);
            // }
        }
        res=max(res,ans);
    }
    ptlle(res);
    return 0;
}