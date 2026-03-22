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
const int N=35;
int t,n,k,up[N],ans[N];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        if(k%2==0){
            int a=0,b=0;
            per(i,30,0){
                if(n>>i&1){
                    a=1<<i;
                    break;
                }
            }//10110=22 10011=19 00101=5 10000=16 00110=6 
            b=n^a;//1010=1000^0110^0100 8+6+4=18 10+10=0
            per(i,30,0){
                int w=1<<i;
                if((a&w) || (b&w))continue;
                if((a|w)<=n && (b|w)<=n){
                    a|=w;
                    b|=w;
                }
            }
            printf("%d %d",a,b);
            rep(i,3,k){
                printf(" %d",n);
            }
            puts("");
        }
        else{
            rep(i,1,k){
                printf("%d%c",n," \n"[i==k]);
            }
        }
    }
    return 0;
}