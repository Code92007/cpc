#include <cstdio>
#include <vector>
using namespace std;
const int mod=998244353;
vector<int> pos[500005];
int a[500005];
int id[500005];
int dp[500005],sum[500005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		pos[i].push_back(-1);
	for(int i=1;i<=n;i++)
	{
		id[i]=pos[a[i]].size();
		pos[a[i]].push_back(i);
	}
	dp[0]=1;
	sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(id[i]>=a[i])
			dp[i]=(sum[pos[a[i]][id[i]-a[i]+1]-1]-sum[pos[a[i]][id[i]-a[i]]]+mod)%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	printf("%d\n",(sum[n]-1+mod)%mod);
	return 0;
}