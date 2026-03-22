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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=5e5+10;
int n,c,d,par[N],q,op,x,y;
ll sum[N];
vector<int>seg[N];
namespace fastIO
{
    static char buf[100000],*h=buf,*r=buf;//缓存开大可减少读入时间，看题目给的空间
    #define gc h==r&&(r=(h=buf)+fread(buf,1,100000,stdin),h==r)?EOF:*h++//不能用fread则换成getchar
    template<typename T>
    inline void read(T&x)
    {
        int f = 1;x = 0;
        register char c(gc);
        while(c>'9'||c<'0'){
            if(c == '-') f = -1;
            c=gc;
        }
        while(c<='9'&&c>='0')x=(x<<1)+(x<<3)+(c^48),c=gc;
        x *= f;
    }
    template<typename T>
    void output(T x)
    {
        if(x<0){putchar('-');x=~(x-1);}
        static int s[20],top=0;
        while(x){s[++top]=x%10;x/=10;}
        if(!top)s[++top]=0;
        while(top)putchar(s[top--]+'0');
    }
}
using namespace fastIO;
int find(int x){
	return par[x]==x?x:find(par[x]);
}
void mer(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return;
    if(SZ(seg[u])<SZ(seg[v]))swap(u,v);
    bool adj=false;
    for(auto &x:seg[v]){
        if(!adj){
            int lfa=find(x-1),rfa=find(x+1);
            if(lfa==u || rfa==u){
                adj=true;
            }
        }
        seg[u].pb(x);
    }
    par[v]=u;
    int w=!adj?c:-d;
    //printf("u:%d v:%d w:%d sumu:%lld sumv:%lld\n",u,v,w,sum[u],sum[v]);
    sum[u]+=sum[v]+w;
}
int main(){
    read(n),read(c),read(d);
    //scanf("%d%d%d",&n,&c,&d);
    rep(i,1,n){
        par[i]=i;
        read(sum[i]);
        //scanf("%lld",&sum[i]);
        seg[i].pb(i);
    }
    read(q);
    //scanf("%d",&q);
    while(q--){
        read(op);
        //scanf("%d",&op);
        if(op==1){
            read(x),read(y);
            //scanf("%d%d",&x,&y);
            mer(x,y);
        }
        else{
            read(x);
            //scanf("%d",&x);
            printf("%lld\n",sum[find(x)]);
        }
    }
    return 0;
}