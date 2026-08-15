
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N=2e6+10;
int t,n,x,y,sz;
unordered_map<int,int>dp,ans;
vector<int>tmp,fac[N];
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int cal(int y,int z){
    if(y==0)return 0;
    if(dp.count(y))return dp[y];
    int w=tmp[z],ans=y/w;
    for(int i=z;i<sz;++i){
        int v=tmp[i];
        //if(v<z)continue;
        if(v>y)break;
        if(v<=w)continue;
        //if(v<=w)ans=min(ans,cal(x+v,y-v)+1);
        //else{
        //if(v%w==0)continue;
        int nex=y/v*v,delta=y-nex,cnt=(delta+w-1)/w;
        if(nex==y)continue;
        //printf("x:%d y:%d z:%d v:%d nex:%d delta:%d cnt:%d\n",x,y,z,v,nex,delta,cnt);
        ans=min(ans,cal(nex,i)+cnt);
        //}
    }
    //printf("x:%d y:%d z:%d ans:%d\n",x,y,z,ans);
    return dp[y]=ans;
}
int main(){
    sci(t);
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            fac[j].pb(i);
        }
    }
    while(t--){
        sci(n);
        if(ans.count(n)){
            printf("%d\n",ans[n]);
            continue;
        }
        int w=n+1;
        dp.clear();
        tmp.clear();
        if(w>=N){
            rep(i,1,32000){
                if(1ll*i*i>w)break;
                if(w%i==0){
                    tmp.pb(i);
                    if(w/i!=i)tmp.pb(w/i);
                }
            }
            sort(tmp.begin(),tmp.end());
        }
        else tmp=fac[n+1];
        sz=SZ(tmp);
        //for(auto &v:tmp)printf("%d ",v);puts("");
        printf("%d\n",ans[n]=cal(n,0));
    }
    return 0;
}