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
const int N=2e5+10,mod=998244353;
int t,n,k,a[N],par[N];
int Finv[N],fac[N],inv[N];
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
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
void mer(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    par[max(x,y)]=min(x,y);
}
int sol(){
    map<int,int>now2;
    int res=1;
    rep(i,1,n){
        if(find(i)==i){ 
            now2.clear();
            int r=i;
            rep(j,i,n){
                if(find(j)!=i)break;
                else r=j;
                now2[a[j]]++;
            }
            int w=r-i+1;
            
            int v=a[i]%k;
            if(v*2==k || v==0){
                //printf("w:%d fac:%d\n",w,fac[w]);
                res=1ll*res*fac[w]%mod;
                for(auto &x:now2){
                    res=1ll*res*Finv[x.se]%mod;
                }
            }
            else{
                int cnt=0;
                rep(j,i,r){
                    if(a[j]%k==a[i]%k)cnt++;
                }
                res=1ll*res*C(w,cnt)%mod;
            }
        }
    }
    return res;
}
int main(){
    init(N-5);
    sci(t);
    while(t--){
        sci(n);sci(k);
        rep(i,1,n){
            sci(a[i]);
            par[i]=i;
        }
        rep(i,2,n){
            if((a[i]+a[i-1])%k==0 || (a[i]%k)==(a[i-1]%k)){
                mer(i-1,i);
            }
        }
        pte(sol());
    }
    return 0;
}