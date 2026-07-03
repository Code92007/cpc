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
const int N=305;
int n,a[N];
bool vis[N];
vector<int>p;
vector<P>gauss,ans;
bool ok;
P f(int v){
	rep(i,1,v){
		rep(j,1,i-1){
			if(i*i+j*j==v){
				return P(i,j);
			}
		}
	}
	return P(-1,-1);
}
void dfs(int i,__int128 a,__int128 b){
	if(ok)return;
	//printf("i:%d a:%lld b:%lld\n",i,a,b);
	if(i==SZ(p)){
		if(a && b){
			ans.pb({a,b});
			ans.pb({a,-b});
			ans.pb({-a,b});
			ans.pb({-a,-b});
			ans.pb({b,a});
			ans.pb({b,-a});
			ans.pb({-b,a});
			ans.pb({-b,-a});
		}
		if(SZ(ans)>=2*n)ok=1;
		return;
	}
	auto [c,d]=gauss[i];
	dfs(i+1,a*c+b*d,b*c-a*d);
	if(ok)return;
	dfs(i+1,a*c-b*d,b*c+a*d);
}
void sol(){
	sci(n);
	for(int i=2;i<N;i++){
		if(!vis[i]){
			if(i%4==1){
				p.pb(i);
				int cnt=1<<(SZ(p)+2);
				if(cnt>=n)break;
			}
			for(int j=2*i;j<N;j+=i){
				vis[j]=1;
			}
		}
	}
	for(auto &v:p){
		gauss.pb(f(v));
	}
	dfs(0,1,0);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	ans.resize(n);
	for(auto &v:ans){
		printf("%lld %lld\n",v.fi,v.se);
	}
}
int main(){
	sol();
	return 0;
}