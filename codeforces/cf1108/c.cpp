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
const int N=2e5+10,mod=1e9+7;
int t,n,a[N];
//1 2 -2 3 -3
map<int,int>cnt,dp[2];
int Finv[N],fac[N],inv[N];
int one[N],zero[N],suf[N];
int modpow(int x,int n,int mod){
	int res=1;
	for(;n;x=1ll*x*x%mod,n>>=1)
	if(n&1)res=1ll*res*x%mod;
	return res;
}
void init(int n){ //n<N
    inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=Finv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod,Finv[i]=1ll*Finv[i-1]*inv[i]%mod;
	//Finv[n]=modpow(fac[n],mod-2,mod);
	//for(int i=n-1;i>=1;--i)Finv[i]=1ll*Finv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	if(m<0||m>n)return 0;
	return 1ll*fac[n]*Finv[n-m]%mod*Finv[m]%mod;
}
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    init(N-5);
    sci(t);
    while(t--){
        sci(n);
        cnt.clear();
        rep(i,0,1){
            dp[i].clear();
        }
        rep(i,1,n){
            sci(a[i]);
            cnt[a[i]]++;
        }
        dp[0][0]=1;
        vector<P>b(cnt.begin(),cnt.end());
        int sz=b.size();
        rep(j,0,sz-1){
            int val=b[j].fi,num=b[j].se;
            one[j]=zero[j]=0;
            rep(k,1,num){
                if(k&1)add(one[j],C(num,k));
                else add(zero[j],C(num,k));
            }
        }
        suf[sz]=suf[sz+1]=1;
        per(j,sz-1,0){
            if(j==sz-1)suf[j]=zero[j]+1;
            else suf[j]=1ll*suf[j+1]*(zero[j]+1)%mod;
        }
        int res=0;
        rep(j,0,sz-1){
            map<int,int>ndp[2];
            rep(y,0,1){
                rep(x,-1,1){
                    ndp[y][x]=dp[y][x];
                }
            }
            if(j+1<sz && b[j+1].fi==b[j].fi+1){
                add(res,1ll*dp[1][-1]*one[j]%mod*one[j+1]%mod*suf[j+2]%mod);
                //printf("j:%d wal:%d\n",j,1ll*dp[1][-1]*one[j]%mod*one[j+1]%mod*suf[j+2]%mod);
            }
            rep(y,0,1){
                rep(x,-1,1){
                    add(ndp[y][x],1ll*dp[y][x]*zero[j]%mod);
                }
            }
            //add(ndp[0][0],1ll*dp[0][0]*zero[j]%mod);
            //add(ndp[1][0],1ll*dp[1][0]*zero[j]%mod);
            //add(ndp[1][-1],1ll*dp[1][-1]*zero[j]%mod);
            if(b[j].fi==-1){
                add(ndp[1][-1],1ll*dp[0][0]*one[j]%mod);
            }
            if(b[j].fi==1){
                add(ndp[1][0],1ll*dp[0][-1]*one[j]%mod);
                add(ndp[1][1],1ll*dp[0][0]*one[j]%mod);
                add(ndp[0][-1],1ll*dp[1][0]*one[j]%mod);
                add(ndp[0][0],1ll*dp[1][1]*one[j]%mod);
            }
            rep(y,0,1){
                rep(x,-1,1){
                    dp[y][x]=ndp[y][x];
                    //printf("j:%d y:%d x:%d dp:%d\n",j,y,x,dp[y][x]);
                }
            }
        }
        rep(y,0,1){
            add(res,dp[y][0]);
        }
        pte(res);
    }
    return 0;
}
/*
-1 
-1 1 = 0
(-1,0)
1 1
(1,0)

*/