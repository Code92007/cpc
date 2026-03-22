#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
bool ok;
vector<int>E[N];
bool vis[N];
char s[N];
int f(int x,int y)
{
	return x*m+y;
}
//构建两条不相交路径 
//找到一条路径 并沿途标记 
void dfs(int x,int y)
{
	if(ok)return;
	vis[f(x,y)]=1;
	if(x==n-1&&y==m-1)
	{
		ok=1;
		return;
	}
	if(x+1<n&&!vis[f(x+1,y)])dfs(x+1,y);
	if(y+1<m&&!vis[f(x,y+1)])dfs(x,y+1); 
} 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%s",s);
		for(int j=0;j<m;++j)
		{
			if(s[j]=='#')
			{
				vis[f(i,j)]=1;
			}
		}
	}
	dfs(0,0);
	if(!ok)puts("0");
	else
	{
		ok=0;
		vis[f(0,0)]=0;
		vis[f(n-1,m-1)]=0;
		dfs(0,0);
		if(!ok)puts("1");
		else puts("2");
	}
	return 0;
}