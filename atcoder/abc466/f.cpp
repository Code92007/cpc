//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
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
using namespace std;
int t,n;
ll x,v;
vector<ll>ans;
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%lld",&x);
        ll now=0;
        ans.clear();
        rep(i,1,n){
            scanf("%lld",&v);
            if(i==1)now=v,ans.pb(v);
            else if(now>v)now=v,ans.pb(v);
        }
        int m=ans.size();
        reverse(ans.begin(),ans.end());
        vector<ll>dp(m,0);
        dp[0]=1;
        rep(i,1,m-1){//[0,x) 方案数 [0,2) [0,4)
            ll now=ans[i];
            int las=i;
            while(now>=ans[0]){
                int l=0,r=las-1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(ans[mid]>now)r=mid-1;
                    else l=mid+1;
                    //printf("i:%d l:%d r:%d mid:%d\n",i,l,r,mid);
                }
                //printf("i:%d r:%d dp:%lld\n",i,r,dp[i]);
                dp[i]+=1ll*(now/ans[r])*dp[r];
                now%=ans[r];
                las=r;
            }
            if(now>0)dp[i]++;
            //printf("i:%d dp:%lld\n",i,dp[i]);
        }
        ll res=0;
        per(i,m-1,0){
            if(x<ans[i])continue;
            res+=1ll*(x/ans[i])*dp[i];
            x%=ans[i];
        }
        printf("%lld\n",res);
    }
    return 0;
}