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
const int N=2e5+10,M=35,K=1e7+10,mod=998244353;
void add(int &x,int y){
	x=(x+y)%mod;
}
struct BitPre{ // 求前缀和(可改为max等)
	int n,tr[K];
	void init(int _n){
		n=_n;
		memset(tr,0,(n+1)*sizeof(*tr));
	}
	void addSum(int x,int v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]=(tr[i]+v)%mod;
	}
	int askSum(int x){
		int ans=0; 
		for(int i=x;i;i-=i&-i)
		ans=(ans+tr[i])%mod;
		return ans;
	}
}tr;
int n,a[N],b[M],dp[N][M];
vector<int>v[N],tmp,all;
vector<array<int,4>>ask[N];
void sol(){
	sci(n);
	rep(i,1,n){
		sci(a[i]);
		per(j,30,0){
			if(a[i]>>j&1){
				b[j]=i;
			}
		}
		tmp.clear();
		per(j,30,0){
			if(b[j]){
				tmp.pb(b[j]);
			}
		}
		if(a[i]==0)tmp.pb(i);
		sort(tmp.begin(),tmp.end(),greater<int>());
		tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
		int now=0,sz=SZ(tmp);
		rep(j,0,sz-1){
			int x=tmp[j];
			now|=a[x];
			v[i].pb(x);
			all.pb(now);
			//if(j)printf("i:%d j:%d now:%d x:%d\n",i,j-1,now,x);
			if(j+1<sz){
                int pre=tmp[j+1];
                ask[pre-1].pb({i,j,now,-1});
            }
			ask[x-1].pb({i,j,now,1});
		}
	}
	all.pb(0);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	//int m=SZ(all);
	tr.init(10000000);
	//tr.addSum(1,1);
	int ans=0;
	rep(i,1,n){
		int now=0,sz=SZ(v[i]);
		rep(j,0,sz-1){
			int x=v[i][j];
			now|=a[x];
			int p=lower_bound(all.begin(),all.end(),now)-all.begin()+1;
			if(j==sz-1)add(dp[i][j],1);
			//printf("i:%d j:%d dp:%d\n",i,j,dp[i][j]);
			tr.addSum(p,dp[i][j]);
			if(i==n)add(ans,dp[i][j]);
		}
		for(auto &x:ask[i]){
			int p=lower_bound(all.begin(),all.end(),x[2])-all.begin()+1;
			//printf("i:%d x0:%d x1:%d x2:%d x3:%d\n",i,x[0],x[1],p,x[3]);
			int sg=x[3];
			if(sg>0)add(dp[x[0]][x[1]],tr.askSum(p));
			else add(dp[x[0]][x[1]],mod-tr.askSum(p));
		}
	}
	pte(ans);
}
int main(){
	sol();
	return 0;
}