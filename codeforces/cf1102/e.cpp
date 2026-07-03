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
typedef pair<ll,int> P//#include<bits/stdc++.h>
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
typedef pair<ll,int> P;
typedef array<int,3> A;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a);
typedef array<int,3> A;
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
const int N=5e5+10,M=20,mod=1e9+7;
int t,n;
ll a[N];
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
ll dfs(int l,int r){
    if(l>r)return 1;
    int pos=-1;
    int sg=0,x=l,y=r;
    while(x<=y){//总能遍历到较短的区间，均摊复杂度O(nlogn)
        if(sg){
            if(1ll*(x-l+1)*(r-x+1)==a[x]){
                pos=x;
                break;
            }
            x++;
        }
        else{
            if(1ll*(y-l+1)*(r-y+1)==a[y]){
                pos=y;
                break;
            }
            y--;
        }
        sg^=1;
    }
    if(pos==-1)return 0;
    return 1ll*dfs(l,pos-1)*dfs(pos+1,r)%mod*C(r-l,pos-l)%mod;
}
int main(){
    init(N-5);
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n){
            scanf("%lld",&a[i]);
        }
        printf("%lld\n",dfs(1,n));
    }
    return 0;
}