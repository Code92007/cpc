#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
vector<int>line[200000],v1,v2;
int qry(int a,int b){
	int x;
	cout<<"? "<<a+1<<' '<<b+1<<'\n';
	cin>>x;
	return x;
}
int dp[200000];
void dfs(int t,int f){
	vector<int>::iterator it;
	dp[t]=t;
	for(it=line[t].begin();it!=line[t].end();it++)
	{
		if(*it==f)continue;
		dfs(*it,t);
		if(dp[*it]!=-1)
		{
			if(dp[t]!=-1)
			{
				v1.push_back(dp[t]);
				v2.push_back(dp[*it]);
				dp[t]=-1;
			}
			else dp[t]=dp[*it];
		}
	}
}
int main(){
//	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,u,v,p;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		for(i=0;i<n-1;i++)
		{
			cin>>u>>v;
			line[u-1].push_back(v-1);
			line[v-1].push_back(u-1);
		}
		dfs(0,-1);
		p=-1;
		for(i=0;i<v1.size();i++)
		{
			if(qry(v1[i],v2[i]))
			{
				p=i;
				break;
			}
		}
		if(p==-1)cout<<"! "<<dp[0]+1<<endl;
		else
		{
			if(qry(v1[p],v1[p]))cout<<"! "<<v1[p]+1<<endl;
			else cout<<"! "<<v2[p]+1<<endl;
		}
		for(i=0;i<n;i++)line[i].clear();
		v1.clear();
		v2.clear();
	}
	return 0;
}