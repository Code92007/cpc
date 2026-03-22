#include <bits/stdc++.h>
using namespace std;
string s;
int dp[500001][7][2],inf=1000000000;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,j,t,flag,ans;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>s;
		if(s=="1")
		{
			cout<<"0\n";
			continue;
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<7;j++)
			{
				for(t=0;t<2;t++)dp[i][j][t]=-inf;
			}
		}
		dp[0][0][0]=0;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<6;j++)
			{
				for(t=0;t<2;t++)
				{
					if(j%2==0)dp[i][j+1][t]=max(dp[i][j+1][t],dp[i][j][t]);//偶数段，切换到下一段时不需要额外处理
					else dp[i][j+1][t]=max(dp[i][j+1][t],dp[i][j][t]-1);//奇数段切换到偶数段时，因为要把奇数段变成0，所以对cnt1-cnt0的贡献是-1，在切换的那一刻统计上一段的贡献
				}
			}
			if(i==n)break;
			for(j=0;j<7;j++)
			{
				for(t=0;t<2;t++)
				{
					if(j%2==1)
					{
						dp[i+1][j][t]=max(dp[i+1][j][t],dp[i][j][t]);//奇数段，一起删掉，此时不用考虑贡献，最后考虑
						continue;
					}
					if(s[i]=='0')dp[i+1][j][t]=max(dp[i+1][j][t],dp[i][j][t]-1);//偶数段，"0"对cnt1-cnt0的贡献是-1
					else dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][t]+1);//偶数段，"1"对cnt1-cnt0的贡献是1，且第三维出现过
				}
			}
		}
		ans=inf;
		for(i=0;i<7;i+=2)ans=min(ans,max(0,-dp[n][i][1])+i/2+1);//010是被视为i=2的，所以实际删掉的奇数段是i/2
		if(ans>n)cout<<"-1\n";//全0的情况
		else cout<<ans+n-1<<'\n';
	}
	return 0;
}