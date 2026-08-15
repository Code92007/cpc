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
const int N=2e5+10,M=2;
int modpow(int x,int n,int mod){
	int res=1;
	for(;n;x=1ll*x*x%mod,n>>=1)
	if(n&1)res=1ll*res*x%mod;
	return res;
}
struct BitPre{ // 求前缀和(可改为max等)
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
        if(x<=0)return 0;
		ll ans=0; 
		for(int i=x;i;i-=i&-i)
		ans+=tr[i];
		return ans;
	}
    ll cal(int l,int r){
        return sum(r)-sum(l-1);
	}
}tr[M];
int mod[M]={19260817,1000000009};
int n,q,a[N],inv[N][M],op,x,y;
int main(){
    sci(n),sci(q);
    rep(j,0,1)tr[j].init(n);
    rep(i,1,n){
        sci(a[i]);
        rep(j,0,1){
            inv[i][j]=modpow(a[i],mod[j]-2,mod[j]);
            //printf("i:%d j:%d inv:%d\n",i,j,inv[i][j]);
            tr[j].add(i,inv[i][j]);
        }
    }
    //printf("%lld\n",tr[0].cal(1,5)%mod[0]);
    while(q--){
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            rep(j,0,1){
                tr[j].add(x,-inv[x][j]);
                a[x]=y;
                inv[x][j]=modpow(a[x],mod[j]-2,mod[j]);
                tr[j].add(x,inv[x][j]);
            }
        }
        else{
            bool ok=1;
            rep(j,0,1){
                int w=tr[j].cal(x,y)%mod[j];
                //printf("j:%d w:%d\n",j,w);
                if(w>y-x+1)ok=0;
            }
            puts(ok?"yes":"no");
        }
    }
    return 0;
}