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
#define scll(a) scanf("%lld",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=2e5+10;
struct BitPre{ // 求前缀和(可改为max等)
	int n;
    ll tr[N];
	void init(int _n){
		n=_n;
		memset(tr,0,(n+1)*sizeof(*tr));
	}
	void add(int x,ll v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]=max(tr[i],v);
	}
	ll ask(int x){
        if(x<=0)return 0;
		ll ans=0; 
		for(int i=x;i;i-=i&-i)
		ans=max(ans,tr[i]);
		return ans;
	}
}tr;
int t,n,a[N];
ll dp[N];
vector<int>add[N];
int main(){
    sci(t);
    while(t--){
        sci(n);
        tr.init(n);
        rep(i,1,n){
            dp[i]=0;
            add[i].clear();
        }
        //i-j>qi且i-j>qj，即j<i-qi且i>qj+j
        //那可以qj+j+1的时候把j插入bit，然后i只询问[1,i-qi-1]
        ll ans=0;
        rep(i,1,n){
            sci(a[i]);
            int r=i-a[i]-1;
            for(auto &p:add[i]){
                tr.add(p,dp[p]);
            }
            dp[i]=tr.ask(r)+a[i];
            int l=a[i]+i+1;
            if(l<=n)add[l].pb(i);
            ans=max(ans,dp[i]);
        }
        ptlle(ans);
    }
    return 0;
}