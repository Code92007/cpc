#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=22*N;
int tr[M][2],tot,num[M];

int head[N],cnt;
int vis[N];
int n,a[N],u,v;
int siz,f[N],sz[N],rt;

int res[N],ans[N],dfn;

struct edge{int v,nex,id;}e[2*N];
void add(int u,int v,int id){
    e[++cnt]=edge{v,head[u],id};
    head[u]=cnt;
} 
void init1(int n){
	cnt=0;
	for(int i=1;i<=n;++i){
		vis[i]=head[i]=0;
	}
    dfn=0;
}

void init2(){
    tot=0;
    memset(tr[0],0,sizeof tr[0]);
    num[0]=0;
}
void add(int x){
    int rt=0;
	for(int i=20;i>=0;--i){
        int v=x>>i&1;
		if(!tr[rt][v]){
            tr[rt][v]=++tot;
            num[tot]=0;
            memset(tr[tot],0,sizeof tr[tot]);
        }
		rt=tr[rt][v];
        num[rt]++;
	}
}
void del(int x){
    int rt=0;
	for(int i=20;i>=0;--i){
        int v=x>>i&1;
		rt=tr[rt][v];
        num[rt]--;
	}
}
int query(int x){
	int rt=0,ans=0;
	for(int i=20;i>=0;--i){
		int j=(x>>i&1)^1;
		if(num[tr[rt][j]]){
			ans|=(1<<i);
			rt=tr[rt][j];
		}
		else rt=tr[rt][1-j];
	}
	return ans;
}

//找下一次的重心rt 
void getrt(int u,int fa,bool op){
	f[u]=0;sz[u]=1;
	for(int i=head[u];i;i=e[i].nex){
		int v=e[i].v;
		if(v==fa||vis[v])continue;
		getrt(v,u,op);
		f[u]=max(f[u],sz[v]);
		sz[u]+=sz[v];
	}
	if(op){
		f[u]=max(f[u],siz-sz[u]);
		if(f[u]<f[rt])rt=u;
	}
}

void cal(int u,int fa,int fid,int op,int now){
    if(op==1){
        add(a[u]);
        //printf("add u:%d au:%d\n",u,a[u]);
    }
    else if(op==-1){
        del(a[u]);
        //printf("del u:%d au:%d\n",u,a[u]);
    }
    else if(op==0){
        //printf("fid:%d au:%d u:%d fa:%d query:%d\n",fid,a[u],u,fa,query(a[u]));
        ans[fid]=query(a[u]);
    }
	for(int i=head[u];i;i=e[i].nex){
		int v=e[i].v,id=e[i].id;
		if(v==fa||(vis[v] && vis[v]<=now))continue;
		cal(v,u,id,op,now);
        if(op==0){
            //printf("fid:%d au:%d query:%d\n",fid,a[u],query(a[u]));
            ans[fid]=max(ans[fid],ans[id]);
        }
    }
    if(op==0){
        res[fid]=max(res[fid],ans[fid]);
    }
}

//计算以u为根的子树的答案
void dfs(int u){
    //printf("rt:%d\n",u);
	vis[u]=++dfn;
	for(int i=head[u];i;i=e[i].nex){
		int v=e[i].v,id=e[i].id;
		if(vis[v] && vis[v]<=vis[u])continue;
        getrt(v,u,0);//获得正确的sz[v] 
		siz=sz[v];rt=0;
		getrt(v,u,1);
		dfs(rt);
    }
    init2();
    //1. 把u下所有点全插进去
    cal(u,0,0,1,vis[u]);
    for(int i=head[u];i;i=e[i].nex){
		int v=e[i].v,id=e[i].id;
		if(vis[v] && vis[v]<=vis[u])continue;
        //2. 把v下所有点全删了
        cal(v,u,id,-1,vis[u]);
        //3. 用v下每个点，在01trie上询问答案
        cal(v,u,id,0,vis[u]);
        //4. 把v下所有点再加回来
        cal(v,u,id,1,vis[u]);
	}
}

int main(){
    scanf("%d",&n);
    init1(n);
    init2();
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        add(u,v,i);
        add(v,u,i);
    }
    f[0]=siz=n;
    rt=0;
    getrt(1,0,1);
    //printf("rt:%d\n",rt);
    dfs(rt);
    for(int i=1;i<n;++i){
        printf("%d\n",res[i]);
    }
	return 0;
}