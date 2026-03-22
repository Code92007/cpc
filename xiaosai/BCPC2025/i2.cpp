//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define SF scanf
#define PF printf
using namespace std;
void Read(int &x){
    char c;
    bool flag=0;
    while(c=getchar(),c!=EOF&&(c<'0'||c>'9')&&c!='-');
    if(c=='-'){c=getchar();flag=1;}
    x=c-'0';
    while(c=getchar(),c!=EOF&&c>='0'&&c<='9')x=x*10+c-'0';
    if(flag==1)x=-x;
}

#define MAXN 100010
#define MAXM 400010
namespace LCT{
    int fa[MAXM],son[MAXM][2];
    bool pre[MAXM],rev[MAXM];
    int siz[MAXM],w[MAXM],sum[MAXM];
    void update(int x){
        sum[x]=sum[son[x][0]]+sum[son[x][1]]+w[x];
        siz[x]=siz[son[x][0]]+siz[son[x][1]]+1;
    }
    void flip(int x){
        swap(son[x][0],son[x][1]);
        rev[x]^=1;
    }
    void pushdown(int x){
        if(rev[x]){
            flip(son[x][0]);
            flip(son[x][1]);
        }
        rev[x]=0;
    }
    void rotate(int x,int d){
        int y=fa[x];
        fa[x]=fa[y];
        pre[x]=pre[y];
        if(fa[y]&&pre[y])
            son[fa[y]][son[fa[y]][1]==y]=x;
        pre[y]=1;
        son[y][!d]=son[x][d];
        if(son[x][d])
            fa[son[x][d]]=y;
        son[x][d]=y;
        fa[y]=x;
        update(y);
        update(x);
    }
    int sta[MAXM];
    void splay(int x){
        int y,z;
        int pnt=0;
        int x1=x;
        while(pre[x1])
            sta[++pnt]=x1,x1=fa[x1];
        sta[++pnt]=x1;
        for(int i=pnt;i>0;i--)
            pushdown(sta[i]);
        while(pre[x]){
            y=fa[x];
            z=fa[y];
            if(!pre[y]){
                rotate(x,son[y][0]==x);
                break;
            }
            if((son[z][0]==y)==(son[y][0]==x)){
                rotate(y,son[z][0]==y);
                rotate(x,son[y][0]==x);
            }
            else{
                rotate(x,son[y][0]==x);
                rotate(x,son[z][0]==x);
            }
        }
        if(rev[x])
            flip(x);
        update(x);
    }
    int Access(int x){
        int last=0;
        while(x){
            splay(x);
            pre[son[x][1]]=0;
            fa[son[x][1]]=x;
            son[x][1]=last;
            if(last)
                pre[last]=1;
            update(x);
            last=x;
            x=fa[last];
        }
        return last;
    }
    void MakeRoot(int x){
        flip(Access(x));
        splay(x);
        rev[x]=!rev[x];
    }
    int FindRoot(int x){
        Access(x);
        splay(x);
        int u=x;
        while(son[u][0]){
            pushdown(u);
            u=son[u][0];
        }
        splay(u);
        return u;
    }
    void Link(int x,int y){
        // if(FindRoot(x)==FindRoot(y))
        //     return ;
        flip(Access(x));
        splay(x);
        flip(Access(y));
        splay(y);
        fa[x]=y;
        sum[y]+=sum[x];
        Access(x);
    }
    void Cut(int x){
        Access(x);
        splay(x);
        pre[son[x][0]]=0;
        fa[son[x][0]]=0;
        son[x][0]=0;
        update(x);
    }
    void Cut(int x,int y){
        flip(Access(x));
        Cut(y);
    }
    int Size(int x){
        Access(x);
        splay(x);
        return sum[x];
    }
}
using namespace LCT;
int lu[MAXM],lv[MAXM];
int res,odd,n,m,q,k,v;
vector<int>tmp;
void prepare(){
    for(int i=1;i<=n+m;i++){
        siz[i]=1;
        if(i<=n)
            w[i]=1,sum[i]=1;
    }
}
void addedge(int idx){
    int u=lu[idx];
    int v=lv[idx];
    //if(Size(u)%2==1&&Size(v)%2==1) odd-=2;
    if(FindRoot(u)==FindRoot(v)){
        res-=max(1,Size(u)/2);
        w[u]^=1;w[v]^=1;
        Link(u,v);
        res+=max(1,Size(u)/2);
    }
    else{
        res-=max(1,Size(u)/2);
        res-=max(1,Size(v)/2);
        w[u]^=1;w[v]^=1;
        Link(u,v);
        res+=max(1,Size(u)/2);
    }
    //MakeRoot(u);
    //printf("u:%d szu:%d\n",u,Size(u));
    //MakeRoot(v);
    //printf("v:%d szv:%d\n",v,Size(v));
    //Link(n+idx,u);
    //Link(n+idx,v); 
    //MakeRoot(u);
    //printf("u:%d szu:%d\n",u,Size(u));
    //printf("idx:%d res:%d\n",idx,res);
}
void deledge(int idx){
    int u=lu[idx];
    int v=lv[idx];
    //MakeRoot(u);
    //Cut(n+idx,u);
    //Cut(n+idx,v);
    res-=max(1,Size(u)/2);
    Cut(u,v);
    w[u]^=1;w[v]^=1;
    if(FindRoot(u)==FindRoot(v)){
        res+=max(1,Size(u)/2);
    }
    else{
        res+=max(1,Size(u)/2);
        res+=max(1,Size(v)/2);
    }
    printf("delidx:%d res:%d\n",idx,res);
    //MakeRoot(v);
    //MakeRoot(u);
    //PF("(%d %d %d %d)\n",Size(u),Size(v),u,v);
}
int main(){
    Read(n),Read(m),Read(q);
    prepare();
    res=n;
    for(int i=1;i<=m;i++){
        Read(lu[i]),Read(lv[i]);
        int u=lu[i],v=lv[i];
        addedge(i);
    }
    printf("res:%d\n",res);
    for(int i=1;i<=q;i++){
        Read(k);
        tmp.clear();
        for(int j=1;j<=k;j++){
            Read(v);
            tmp.push_back(v);
            deledge(v);
        }
        printf("%d\n",res);
        for(auto &v:tmp){
            addedge(v);
        }
    }
}