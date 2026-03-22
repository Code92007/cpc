#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;
#define ull unsigned long long
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
int t,n,a[N];
map<int,vector<int> >mp;
struct BitPre{ // 求前缀和(可改为max等)
	int n,tr[N];
	void init(int _n){
		n=_n;
		memset(tr,0,(n+1)*sizeof(*tr));
	}
	void add(int x,int v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]+=v;
	}
	int sum(int x){
		int ans=0; 
		for(int i=x;i;i-=i&-i)
		ans+=tr[i];
		return ans;
	}
}tr;
int main(){
    sci(t);
    while(t--){
        sci(n);
        mp.clear();
        tr.init(n);
        rep(i,1,n){
            sci(a[i]);
            tr.add(i,1);
            mp[a[i]].pb(i);
        }
        ll ans=0;
        for(auto it=prev(mp.end());;it=prev(it)){
            auto x=*it;
            //printf("x.fi:%d\n",x.fi);
            for(auto &pos:x.se){
                //printf("pos:%d\n",pos);
                tr.add(pos,-1);
            }
            int all=tr.sum(n);
            //printf("all:%d\n",all);
            for(auto &pos:x.se){
                int pre=tr.sum(pos);
                //printf("pre:%d all-pre:%d\n",pre,all-pre);
                ans+=min(pre,all-pre);
            }
            if(it==mp.begin())break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}