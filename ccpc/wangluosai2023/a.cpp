#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2e6+10,MOD=998244353;
char s[N],t[N],w[M];
int n,m,up,f[N],way[N],sum[N],sq[N];
namespace Hash{
    const int K=2;
    const int bs[K]={19260817,19491001};
    const int mod[K]={1000000007,1000000009};
    int hs[K][M],pw[K][M];
    int cal(int k,int l,int r){
        int *val=hs[k],*base=pw[k];
        int w=mod[k];
        return (val[r]-1ll*val[l-1]*base[r-l+1]%w+w)%w;
    }
    void init(char *w,int up){
        for(int k=0;k<K;++k){
            int *val=hs[k],*base=pw[k];
            int B=bs[k],W=mod[k];
            val[0]=base[0]=1;
            for(int i=1;i<=up;++i){
                base[i]=1ll*base[i-1]*B%W;
                val[i]=(1ll*val[i-1]*B+w[i])%W;
            }
        }
    }
    bool same(int x,int y,int len){
        for(int k=0;k<K;++k){
            if(cal(k,x,x+len-1)!=cal(k,y,y+len-1))return 0;
        }
        return 1;
    }
    int lcp(int x,int y){
        if(x>up || y>up)return 0;
        int l=0,r=up-max(x,y)+1;
        while(l<=r){
            int mid=(l+r)/2;
            if(same(x,y,mid))l=mid+1;
            else r=mid-1;
        }
        return r;
    }
}
using namespace Hash;
void add(int &x,int y){
    x+=y;
    if(x>=MOD)x-=MOD;
}
void add(int *a,int l,int r,int v){
    add(a[l],v);
    add(a[r+1],MOD-v);
}
int main(){
    scanf("%s%s",s+1,t+1);  
    n=strlen(s+1);
    m=strlen(t+1);
    up=n+m+1;
    sprintf(w+1,"%s#%s",t+1,s+1);
    init(w,up);
    int s0=0,s1=0,s2=0;
    add(way,1,1,1);
    for(int i=1;i<=n+1;++i){
        add(s0,way[i]);
        add(s1,sum[i]);
        add(s2,sq[i]);
        if(i==n+1)break;
        int lim=min(m,n-i+1);
        int st=m+1+i;
        int fir=min(lcp(1,st),lim);
        if(fir==lim)f[i]=lim;
        else{
            int sec=lcp(fir+2,st+fir+1);
            f[i]=min(fir+sec+1,lim);
        }
        int n1=(s0+s1)%MOD;
        int n2=(s2+2ll*s1+s0)%MOD;
        int L=i+1,R=i+f[i];
        add(way,L,R,s0);
        add(sum,L,R,n1);
        add(sq,L,R,n2);
    }
    printf("%d\n",s2);
    return 0;
}