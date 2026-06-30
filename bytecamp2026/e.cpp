#include<bits/stdc++.h>
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
typedef array<int,3> A;
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
const int N=65,K=60,B=39,mod=1e9+7;
const ll INF=1e12;
ll n,m,f[N];
int used[N],cnt=mod;
vector<int>no;
void dfs(int i,ll xo,int c,ll sum){
    if(i==SZ(no)){
        ll v=xo^n;
        per(j,B,0){
            if(v>>j&1){
                if(!used[j])return;
                v^=f[used[j]];
                sum+=f[used[j]];
                c++;
            }
        }
        if(v || sum>m)return;
        ll del=m-sum;
        if(del%2)return;
        del/=2;
        //printf("i:%d no:%lld c:%d sum:%lld\n",i,xo,c,sum);
        //printf("v:%lld del:%lld\n",v,del);
        per(i,K,1){
            if(del>=f[i]){
                del-=f[i];
                c+=2;
            }
        }
        cnt=min(cnt,c);
        return;
    }
    dfs(i+1,xo,c,sum);
    ll v=f[no[i]];
    dfs(i+1,xo^v,c+1,sum+v);
}
void sol(){
    if(n>m){
        puts("-1");
        return;
    }
    f[1]=1;
    rep(i,2,K){
        f[i]=f[i-1]+f[i-2];
    }
    rep(i,1,K){
        if(f[i]>INF)continue;
        int b=0;
        per(j,B,0){
            if(f[i]>>j&1){
                b=j;
                break;
            }
        }
        if(!used[b]){
            used[b]=i;
            //printf("i:%d b:%d fusedb:%lld\n",i,b,f[i]);
        }
        else{
            no.pb(i);
        }
    }
    // rep(i,0,B){
    //     printf("i:%d used:%d v:%lld\n",i,used[i],f[used[i]]);
    // }
    // pte(SZ(no));
    // for(auto &v:no){
    //     printf("%d ",v);
    // }
    // puts("");
    dfs(0,0,0,0);
    //printf("cnt:%d\n",cnt);
    if(cnt>=mod)puts("-1");
    else pte(cnt);
}
int main(){
    scanf("%lld%lld",&n,&m);
    sol();
    return 0;
}
/*
1 1 2 3 5 8 13 21 34 55 89
*/