//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
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
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,n,x,y,a[N];
ll sum[N],pre[N],suf[N];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(x),sci(y);
        rep(i,1,n){
            sci(a[i]);
            sum[i]=sum[i-1]+a[i];
            pre[i]=a[i]-(a[i]&y);
            if(i>1)pre[i]=min(pre[i],pre[i-1]);
        }
        per(i,n,1){
            suf[i]=a[i]-(a[i]&y);
            if(i<n)suf[i]=min(suf[i],suf[i+1]);
        }
        ll ans=1e18;
        rep(i,1,n){
            ll v=a[i]|x,w=v&y;
            w=v-w;
            ll mncost=w;
            if(i+1<=n)mncost=min(mncost,1ll*suf[i+1]);
            if(i-1>=1)mncost=min(mncost,1ll*pre[i-1]);
            ll tmp=sum[n]-a[i]+v-mncost;
            ans=min(ans,tmp);
        }
        printf("%lld\n",ans);
    }
    return 0;
}