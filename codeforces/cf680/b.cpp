#include<bits/stdc++.h>
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
const int N=3e5+10,mod=998244353;
int n,a[N],ans;
int Finv[N],fac[N],inv[N],sum[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
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
int cal(int l,int r){
    if(l==0)return sum[r];
    int v=sum[r]-sum[l-1];
    v=(v+mod)%mod;
    return v;
}
int main(){
    init(N-5);
    sci(n);
    int m=2*n;
    rep(i,1,m){
        sci(a[i]);
    }
    // rep(i,0,n){
    //     sum[i]=C(n,i);
    //     //printf("i:%d sum:%d\n",i,sum[i]);
    //     if(i)sum[i]=(sum[i-1]+sum[i])%mod;
    // }
    sort(a+1,a+m+1);
    int sum=0;
    rep(i,1,n){
        sum=(sum+mod-a[i])%mod;
        sum=(sum+a[i+n])%mod;
    }
    printf("%d\n",1ll*C(2*n,n)*sum%mod);
    // int c1=0;
    // rep(i,1,m){
    //     if(i-1>=n){
    //         if(a[i]==a[i+1]){
    //             c1++;
    //             continue;
    //         }
    //         else{
    //             //int v=modpow(2,n,mod)-1;
    //             //v=(v+mod)%mod;
    //             int v=cal(i-1-n,n-1);//C(n,i-1-n)
    //             int w=1ll*C(i-1,n)*v%mod;
    //             w=1ll*w*a[i]%mod;
    //             printf("i:%d v:%d w:%d\n",i,v,w);
    //             add(ans,1ll*c1*w%mod);
    //             c1=1;
    //         }
    //     }//m-i+1+x>=n,x>=i-1-n
    // }
    // int c2=0;
    // per(i,m,1){
    //     if(m-i>=n){
    //         if(a[i]==a[i-1]){
    //             c2++;
    //             continue;
    //         }
    //         //int v=modpow(2,n,mod)-1;
    //         else{
    //             int v=cal(n-i,n-1);
    //             v=(v+mod)%mod;
    //             int w=1ll*C(m-i,n)*v%mod;
    //             w=1ll*w*(-a[i])%mod;
    //             //w=(w+mod)%mod;
    //             printf("i:%d v:%d w2:%d\n",i,v,w);
    //             add(ans,1ll*c2*w%mod);
    //             c2=1;
    //         }
    //     }//i-1+1+x>=n,x>=n-i
    // }
    //printf("%d\n",2ll*ans%mod);
    return 0;
}
/*
1 1 2 2 

1 2 3 4 5 6
3 4 5
6 2 1

1 2 3 4 5 6 7 8 9 10
6 7 8 9 10 
5 4 3 2 1
5 7 8 9 10
6 4 3 2 1
4 7 8 9 10
6 5 3 2 1
3 7 8 9 10
6 5 4 2 1
5 7 8 9 10
6 4 3 2 1
C(little,n)*(C(n,0)+C(n,1)+C(n,n-1))
C(little,n)*(2^n-1)
2 3 5
6 4 1
C(2*n,n)
对于pi的位置
C(little,n)
如果n-i的位置选了

p[i]=y
q[i]=x
y>x

*/