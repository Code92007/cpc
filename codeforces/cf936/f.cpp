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
const int N=1e6+10;
struct BitPre{ // 求前缀和(可改为max等)
	int n;
    ll tr[N];
	void init(int _n){
		n=_n;
		memset(tr,0,(n+1)*sizeof(*tr));
	}
	void add(int x,ll v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]+=v;
	}
	ll sum(int x){
		ll ans=0; 
		for(int i=x;i;i-=i&-i)
		ans+=tr[i];
		return ans;
	}
}tr;
int t,n,q,l,r,a[N],pos[N];
ll dp[N],ans[N];
vector<P>ask[N];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(q);
        rep(i,1,n){
            sci(a[i]);
            ask[i].clear();
            pos[a[i]]=i;
        }
        tr.init(n);
        rep(i,1,q){
            sci(l),sci(r);
            ask[l].pb(P(i,r));
        }
        per(l,n,1){   
            for(int j=a[l];j<=n;j+=a[l]){
                dp[j]=0;
            }
            dp[a[l]]=1;
            for(int j=a[l];j<=n;j+=a[l]){
                if(pos[j]<l)continue;
                for(int k=2*j;k<=n;k+=j){
                    if(pos[k]<pos[j])continue;
                    dp[k]+=dp[j];
                }
                tr.add(pos[j],dp[j]);
            }
            for(auto &x:ask[l]){
                int id=x.fi,r=x.se;
                ans[id]=tr.sum(r)-tr.sum(l-1);
            }
        }
        rep(i,1,q){
            printf("%lld ",ans[i]);
        }
        puts("");
    }
    return 0;
}