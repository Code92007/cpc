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
typedef pair<ll,ll> P;
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
const int N=2e5+10,M=20;
int t,n,m,u,v,dp[N],mx[N],stk[N],p[N],c;
vector<int>tmp;
vector<int>e[N];
struct BitPre{
	int n;
    ll tr[N];
	void init(int _n){
		n=_n;
		memset(tr,0,(n+1)*sizeof(*tr));
	}
	void add(int x,int v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]+=v;
	}
	ll sum(int x){
		ll ans=0; 
		for(int i=x;i;i-=i&-i)
		ans+=tr[i];
		return ans;
	}
}tr1,tr2;
int main(){
    sci(t);
    while(t--){
        sci(n);sci(m);
        tr1.init(n);tr2.init(n);
        rep(i,1,n)e[i].clear();
        rep(i,1,n-1){
            mx[i]=i+1;
        }
        rep(i,1,m){
            sci(u),sci(v);
            mx[u]=max(mx[u],v);
        }
        dp[n]=0;
        per(i,n-1,1){
            dp[i]=n-i;
            for(auto &x:e[i]){
                dp[i]=min(dp[i],dp[x]+1);
            }
        }
        c=0;
        rep(i,1,n){//枚举tom最终停留点
            if(c){
                int l=1,r=c;//递减栈
                while(l<=r){
                    int mid=(l+r)/2;
                    if(mx[stk[mid]]>i)l=mid+1;
                    else r=mid-1;
                }
                if(l>c){
                    p[i]=n+1;
                }
                else{//[stk[l],i]
                    p[i]=stk[l];
                }
            }
            else{
                p[i]=n+1;
            }
            while(c && mx[stk[c]]<=mx[i])c--;
            stk[++c]=i;
        }
        ll ans=0;
        rep(i,1,n){
            if(p[i]>n)continue;
            if(p[i]==p[i-1]){
                int cnt=tr1.sum(dp[i]),cnt2=tr1.sum(n)-cnt;
                ans+=tr2.sum(dp[i])-1ll*cnt*dp[i];
                ans+=1ll*cnt2*(dp[i]-dp[i]);
                tr1.add(dp[i],1);
                tr2.add(dp[i],dp[i]);
                tmp.pb(dp[i]);
            }
            else{
                for(auto &v:tmp){
                    tr1.add(v,-1);
                    tr2.add(v,-v);
                }
                tmp.clear();
                rep(j,p[i],i){
                    
                    tmp.pb(dp[j]);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}