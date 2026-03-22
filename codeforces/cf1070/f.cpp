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
const int maxp = 2e5+10,N=maxp,M=14,mod=998244353;
int tot, pr[maxp], d[maxp];
int t,n,k,v,w[N],r[N];//w是素因子种类数，r是去重素因子后得到的数
//dp[i][j]表示gcd=i 二者w之和为j时的方案数
//w(x*y)=w(x)+w(y)-w(gcd(x,y))
int cnt[N][7],dp[N][M];
int bs[M];
void add(int &x,int y){
    x=(x+y)%mod;
}
int modpow(int x,int n,int mod){
    int res=1;
    for(;n;n/=2,x=1ll*x*x%mod){
        if(n&1)res=1ll*res*x%mod;
    }
    return res;
}
int main(){
    r[1]=1;
    for(int i = 2; i < maxp; ++i) {
		if(!d[i])
		    pr[tot++] = d[i] = i, w[i]=1;
		for(int j = 0, k; (k = i * pr[j]) < maxp; ++j) {
		    d[k] = pr[j];
		    if(d[i] == pr[j])
		        break;
		}
        if(d[i]==d[i/d[i]])w[i]=w[i/d[i]],r[i]=r[i/d[i]];
        else w[i]=w[i/d[i]]+1,r[i]=r[i/d[i]]*d[i];
        //printf("i:%d di:%d wi:%d ri:%d\n",i,d[i],w[i],r[i]);
	}
    sci(t);
    while(t--){
        sci(n),sci(k);
        bs[0]=0;bs[1]=1;
        rep(i,2,12){
            bs[i]=modpow(i,k,mod);
        }
        rep(i,1,n){
            rep(j,0,12){
                dp[i][j]=0;
            }
            rep(j,0,6){
                cnt[i][j]=0;
            }
        }
        rep(i,1,n){
            sci(v);
            v=r[v];
            //printf("v:%d w:%d\n",v,w[v]);
            cnt[v][w[v]]++;
        }
        rep(i,1,n){
            vector<int>now(7,0);
            rep(k,0,6){
                for(int j=i;j<=n;j+=i){
                    now[k]+=cnt[j][k];
                }
                cnt[i][k]=now[k];
            }
            // rep(k,0,6){
            //     ;//cnt[i][k]此时表示第一维是i的倍数，第二维w=k的数的个数
            //     printf("i:%d k:%d cnt:%d\n",i,k,cnt[i][k]);
            // }
        }
        int ans=0;
        per(i,n,1){
            rep(j,0,6){
                rep(k,j,6){
                    if(j<k)add(dp[i][j+k],1ll*cnt[i][j]*cnt[i][k]%mod);
                    else if(j==k)add(dp[i][j+k],1ll*cnt[i][j]*(cnt[i][j]-1)/2%mod);
                }
            }
            for(int j=2*i;j<=n;j+=i){
                rep(k,0,12){
                    add(dp[i][k],mod-dp[j][k]);
                }
            }
            rep(k,0,12){
                if(!dp[i][k])continue;
                //printf("i:%d k:%d wsum:%d dp:%d\n",i,k,k-w[i],dp[i][k]);
                int wsum=k-w[i];
                add(ans,1ll*dp[i][k]*bs[wsum]%mod);
            }
        }
        pte(ans);
    }
    return 0;
}