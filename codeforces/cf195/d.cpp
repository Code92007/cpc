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
typedef pair<int,int> P;
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
// /submit 枚举从左到右第一个1的位置i 因为从右到左合并遇到这个1的时候一定会变成0 最后的答案也会被确定 用组合数指定[i+1，n]的0的数量
const int N=2e5+10,mod=1e9+7;
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
int n,m,g,ans;
void add(int &x,int y){x=(x+y)%mod;}
int main(){
    init(N-5);
    sci(n),sci(m),sci(g);
    if(n==0){
        if(g==1)pte(m==1?1:0);
        else pte(m>1?1:0);
        return 0;
    }
    if(m==0){
        pte(((n&1)^1)==g?1:0);
        return 0;
    }
    rep(i,1,n+1){
        int left=i-1,cur;
        int rig=n-left+m-1,need=n-left;
        if(!rig)cur=1;
        else cur=0;
        left%=2;
        if(left)cur^=1;
        if(cur==g){
            //printf("i:%d rig:%d n-lef:%d\n",i,rig,need);
            add(ans,C(rig,need));
        }
    }
    pte(ans);
    return 0;
}