//#include <bits/stdc++.h>
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
const int maxn=1e7+10;
int t,m,k,v;
bool can[10];
typedef long long ll;
bool ok[maxn];
int prime[maxn],phi[maxn],cnt;
void sieve()
{ 
    phi[1]=1;
	for(ll i=2;i<maxn;++i)
	{
		if(!ok[i])
		{
			prime[cnt++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<cnt;++j)
		{
			if(i*prime[j]>=maxn)break;
			ok[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];//prime[j]是i的因子 prime[j]的素因子项包含在i的素因子项里
				break; 
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);//prime[j]与i互质 phi[i*prime[j]=phi[i]*phi[prime[j]]
		}
	}
}
void sol(){
    // rep(i,1,1){
    //     ll w=i*m;
    //     //printf("i:%d w:%d\n",i,w);
    //     if(ok(w)){
    //         out(w);
    //         return;
    //     }
    // }
    if(k==9){
        puts("-1");
        return;
    }
    int w=0;
    rep(i,1,9){
        if(can[i]){
            w=i;
            break;
        }
    }
    // int c=1,n=m;
    // while(n%2==0)n/=2,c++;
    // while(n%5==0)n/=5,c++;
    printf("%d\n",2);
    printf("%d %lld\n",w,1ll*m*phi[m]);
    printf("%d %d\n",0,300);
}
int main(){
    sieve();
    sci(t);
    while(t--){
        sci(m),sci(k);
        rep(i,0,9)can[i]=1;
        rep(i,1,k){
            sci(v);
            can[v]=0;
        }
        sol();
    }
    return 0;
}