//#include<bits/stdc++.h>
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
typedef pair<ll,ll> P;
typedef array<ll,3> A;
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
const int N=5e3+10,mod=998244353;
int t,n,w[N],f[N],h[N],a[2],b[N][N],g[N];//可行101,010,10,01,1,0。100不行 0101
//b[i][j]表示i个数放j个集合的方案数 贝尔数
bool can[N];
char s[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
int upd(int &x,int y){
    if(x<y){
        x=y;
        return 1;
    }
    else if(x==y){
        return 0;
    }
    return -1;
}
P sol(int l,int r){
    int m=r-l+1;
    rep(i,1,m){
        w[i]=s[l-1+i]-'0';
        f[i]=h[i]=0;
    }
    f[0]=0,h[0]=1;
    rep(i,1,m){
        if(i-2>=1 && w[i-2]==w[i] && w[i-1]!=w[i]){//101
            int op=upd(f[i],f[i-3]+6);
            if(op==1)h[i]=h[i-3];
            else if(op==0)add(h[i],h[i-3]);
        }
        if(i-1>=1 && w[i-1]!=w[i]){//10
            int op=upd(f[i],f[i-2]+4);
            if(op==1)h[i]=h[i-2];
            else if(op==0)add(h[i],h[i-2]);
        }
        int op=upd(f[i],f[i-1]+1);
        if(op==1)h[i]=h[i-1];
        else if(op==0)add(h[i],h[i-1]);
    }
    return P(f[m],h[m]);
}
int main(){
    b[1][1]=1;
    int up=5e3;
    rep(i,2,up){
        rep(j,1,i-1){
            add(b[i][j],1ll*b[i-1][j]*j%mod);//挑一个
            add(b[i][j+1],b[i-1][j]);//新开一个
        }
    }
    g[0]=1;
    rep(i,1,up){
        rep(j,1,i){
            add(g[i],b[i][j]);
        }
        //printf("i:%d gi:%d\n",i,g[i]);
    }
    sci(t);
    while(t--){
        sci(n);
        scanf("%s",s+1);
        rep(i,1,n)can[i]=0;
        a[0]=a[1]=0;
        rep(i,1,n){
            if(i-1>=1 && s[i-1]!=s[i])can[i-1]=can[i]=1;
            if(i+1<=n && s[i+1]!=s[i])can[i+1]=can[i]=1;
        }
        P res=P(0,1);
        for(int i=1;i<=n;){
            if(!can[i]){
                res.fi++;
                a[s[i]-'0']++;
                i++;
                continue;
            }
            int j=i;
            while(j+1<=n && can[j+1]){
                j++;
            }
            P x=sol(i,j);
            res.fi+=x.fi;
            res.se=1ll*res.se*x.se%mod;
            i=j+1;
        }
        res.se=1ll*res.se*g[a[0]]%mod*g[a[1]]%mod;
        printf("%lld %lld\n",res.fi,res.se);
    }
    return 0;
}