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
const int N=1e6+10,K=(1<<20),M=20;
int n,q,a[N];
ll sum[M][N],k,s,need;
//首次非子集，00100，00011，贡献2^x-(a[i]&(2^x-1))，对于右起第三位
//第二次非子集，01100，00011，贡献2^x，对于右起第三位
//还是不会写，补一下吧，2500的题
int main(){
    sci(n),sci(q);
    rep(i,1,n){
        sci(a[i]);
        need+=K-a[i];
    }
    int up=(1<<20)-1;
    rep(x,0,19){
        ll *b=sum[x];
        rep(i,1,n){
            if(!(a[i]>>x&1))//前缀已经不是子集了，贡献2^x，否则贡献2^x-(a[i]&(2^x-1));首次非子集和第二次非子集
         }
        rep(j,0,19){
            rep(k,0,up){
                if(!(k>>j&1))b[k]=b[k]+b[k|(1<<j)];
            }
        }
    }
    while(q--){
        scanf("%lld",&k);
        if(k>=need){
            printf("%lld\n",K+(k-need)/n);
            continue;
        }
        int ans=0;
        per(i,19,0){
            int cnt=b[ans]
        }
    }
    return 0;
}