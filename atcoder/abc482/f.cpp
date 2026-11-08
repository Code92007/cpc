//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
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
const int N=4e5+10,M=20,INF=0x3f3f3f3f;
ll val[N],c[N];
ll n;
int m,tot,ans[N];
bool in[N][M];
vector<ll>fac;
queue<P>q;
int main(){
    scanf("%lld%d",&n,&m);
    int up=1e7;
    rep(i,2,up){
        if(n%i==0){
            val[++tot]=i;
            while(n%i==0){
                n/=i;
                c[tot]++;
            }
        }
    }
    if(n>1){
        val[++tot]=n;
        c[tot]=1;
    }
    // rep(i,1,tot){
    //     printf("w:%lld c:%d\n",val[i],c[i]);
    // }
    memset(ans,INF,sizeof ans);
    if(tot==0){
        rep(i,0,m-1){
            if(i==1%m)puts("1");
            else puts("-1");
        }
        return 0;
    }
    ans[1%m]=1;
    q.push(P(1%m,0));
    while(!q.empty()){
        P x=q.front();
        q.pop();
        int w=x.fi,nex=x.se%tot+1;
        int up=c[nex];
        rep(i,0,up){
            if(!in[w][nex%tot]){
                in[w][nex%tot]=1;
                if(nex==tot)ans[w]=(x.se+1)/tot;
                q.push(P(w,x.se+1));
            }
            w=1ll*w*(val[nex]%m)%m;
        }
    }
    rep(i,0,m-1){
        if(ans[i]==INF)puts("-1");
        else printf("%d\n",ans[i]);
    }
    return 0;
}