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
const int N=1e5+10,bs=1<<20;
char s[N];
int n,one,c1,c2,a[N];
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    rep(i,1,n){
        one+=(s[i]=='1');
    }
    rep(i,1,n){
        if(s[i]=='0')a[i]=++c1;
        else a[i]=++c2,a[i]+=bs;
    }
    if(c2%2==0){
        if(!c2){
            rep(i,1,n){
                if(s[i]=='0'){
                    a[i]+=bs;
                    break;
                }
            }
        }
        else{
            rep(i,1,n){
                if(s[i]=='1'){
                    a[i]=++c1;
                    break;
                }
            }
        }
    }
    rep(i,1,n){
        printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}