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
const int N=1e3+10,M=66,mod=998244353;
int n,m,op,a[N],two[N],cnt[M],now[M],b[N],d[M],nex[M],c,len;
int dp[M][N];
ll x;
//前面填过now[p+1]位了，该填第p位了，要决策q个数要不要填
//如果填，贡献就是第b[q]-now[p+1]位
//lim卡上界就是前面全相等，不卡上界就是已经大了后面随便选
int dfs(int p,int q){
    //printf("p:%d q:%d\n",p,q);
    if(p<0 || nex[p]==-1)return two[q];
    if(q==0)return 0;
    if(~dp[p][q])return dp[p][q];
    int ret=0;
    int next=b[q]-now[p+1];
    if(nex[p]>next)return 0;
    //printf("p:%d q:%d d[p]:%d nex[p]:%d next:%d\n",p,q,d[p],nex[p],next);
    ret=(ret+dfs(p,q-1))%mod;//不填
    if(nex[p]==next)ret=(ret+dfs(next-1,q-1))%mod;//填
    else if(nex[p]<next)ret=(ret+two[q-1])%mod;//填
    //return ret;
    //printf("p:%d q:%d ret:%d\n",p,q,ret);
    return dp[p][q]=ret;
}
/*

(2,2)=[2,1]=5 1种
(2,1)=[2,0]=4 4种
(2,1,1) 2种
(2,2,1) 2种
(2,2,1,1) 1种

(1,1)
(2,1)*2
(2,1,1)*1
(1)*2
(2)*1
*/
int init(ll x){
    c=0;
    rep(i,0,63){
        rep(j,1,cnt[i]){
            b[++c]=i;
        }
    }
    // rep(i,1,c){
    //     printf("i:%d b:%d\n",i,b[i]);
    // }
    len=0;
    for(;x;x/=2){
        d[len++]=x%2;
    }
    d[len]=0;
    now[len+1]=now[len]=0;
    per(i,len-1,0){
        now[i]=now[i+1]+d[i];
    }
    int las=-1;
    rep(i,0,len){
        if(d[i]==1)las=i;
        nex[i]=las;
    }
    // per(i,len,0){
    //     printf("i:%d now:%d nex:%d\n",i,now[i],nex[i]);
    // }
    memset(dp,-1,sizeof dp);
    return dfs(len,c);
}
int main(){
    two[0]=1;
    rep(i,1,N-1)two[i]=2ll*two[i-1]%mod;
    sci(n),sci(m);
    rep(i,1,n){
        sci(a[i]);
        cnt[a[i]]++;
    }
    while(m--){
        sci(op);
        scanf("%lld",&x);
        if(op==1)cnt[x]++;
        else if(op==2)cnt[x]--;
        else printf("%d\n",init(x));
    }
    return 0;
}