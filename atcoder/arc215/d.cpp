#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int mod=1e9+7; 
const int N=2e7+10;
int n,m,Finv[N],fac[N],inv[N];
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
int main(){
    init(N-5);
    scanf("%d%d",&n,&m);
    n++;
    int odd=n-n/2,even=n/2;
    //printf("odd:%d even:%d\n",odd,even);
    odd--;
    int ans1=1ll*C(m+odd,odd)*C(m+even,even)%mod;
    odd++;
    even--;
    int ans2=1ll*C(m+odd,odd)*C(m+even,even)%mod;
    even++;
    odd--;
    even--;
    int ans3=1ll*C(m+odd,odd)*C(m+even,even)%mod;
    int ans4=((ans1+ans2)%mod-ans3+mod)%mod;
    //printf("ans1:%d ans2:%d ans3:%d\n",ans1,ans2,ans3);
    printf("%lld\n",ans4);
	return 0;
}