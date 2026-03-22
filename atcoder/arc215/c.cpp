//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
struct node{
	int v,id;
	node(){}
	node(int vv,int i):v(vv),id(i){
	}
}tmp;
bool operator<(node a,node b)
{
	return a.v<b.v;
}
priority_queue<node>p[3];
int mn[3],a[3][maxn];
int n,q,v;
bool ok[maxn],flag;
void sol(){
    for(int i=0;i<3;++i){
        while(!p[i].empty())p[i].pop();
    	mn[i]=INF;
    }
	scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        ok[i]=false;
        for(int j=0;j<3;++j)
        {
            scanf("%d",&a[j][i]);
            p[j].push(node(a[j][i],i));
        }
    }
	for(int i=0;i<3;++i)
	{
		tmp=p[i].top();p[i].pop();
        //printf("i:%d tmpid:%d\n",i,tmp.id);
		ok[tmp.id]=1;
		mn[i]=min(mn[i],a[i][tmp.id]);
		mn[(i+1)%3]=min(mn[(i+1)%3],a[(i+1)%3][tmp.id]);
		mn[(i+2)%3]=min(mn[(i+2)%3],a[(i+2)%3][tmp.id]);
	}
	flag=1; 
	while(flag)
	{
		flag=0;
		for(int i=0;i<3;++i)
		{
			while(!p[i].empty()&&p[i].top().v>=mn[i])
			{
				tmp=p[i].top();p[i].pop();
				if(ok[tmp.id])continue;
				ok[tmp.id]=1;flag=1;
				mn[(i+1)%3]=min(mn[(i+1)%3],a[(i+1)%3][tmp.id]);
				mn[(i+2)%3]=min(mn[(i+2)%3],a[(i+2)%3][tmp.id]);
			}
		}
	}
    int ans=0;
    for(int i=1;i<=n;++i){
        if(ok[i])ans++;
    }
    printf("%d\n",ans);
}
int main()
{
	int t;
    scanf("%d",&t);
    while(t--){
        sol();
    }
	return 0;
} 