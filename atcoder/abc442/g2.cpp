#include <bits/stdc++.h>
using namespace std;
struct apos{
	long long v;
	long long w;
	long long k;
	friend bool operator<(apos a,apos b){
		return a.v*b.w>b.v*a.w;
	}
}ap[200000];
long long dp[9],ck[200000],inf=1000000000000000000LL;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	long long n,c,i,j,t,d,ans0,ans;
	cin>>n>>c;
	for(i=0;i<n;i++)cin>>ap[i].w>>ap[i].v>>ap[i].k;
	sort(ap,ap+n);
	ans0=0;
	for(i=0;i<n;i++)
	{
		d=min(ap[i].k,c/ap[i].w);
		ans0+=d*ap[i].v;
		c-=d*ap[i].w;
		ck[i]=d;
		if(d!=ap[i].k)break;
	}
	if(i==n)
	{
		cout<<ans0<<'\n';
		return 0;
	}
	for(i=0;i<=8;i++)dp[i]=-inf;
	dp[8-c]=ans0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=8;j++)
		{
			for(t=1;t<=ck[i]&&j-t*ap[i].w>=0;t++)dp[j-t*ap[i].w]=max(dp[j-t*ap[i].w],dp[j]-t*ap[i].v);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=8;j>=0;j--)
		{
			for(t=1;t<=ap[i].k-ck[i]&&j+t*ap[i].w<=8;t++)dp[j+t*ap[i].w]=max(dp[j+t*ap[i].w],dp[j]+t*ap[i].v);
		}
	}
	ans=-inf;
	for(i=0;i<=8;i++)ans=max(ans,dp[i]);
	cout<<ans<<'\n';
	return 0;
}