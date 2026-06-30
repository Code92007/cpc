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
const int N=1e6+10,mod=998244353;
int t,p,q,c;
char s[N];
int main(){
    sci(t);
    while(t--){
        sci(p),sci(q);
        c=0;
        while(p!=1 || q!=1){
            if(p<q)q-=p,s[c++]='L';
            else p-=q,s[c++]='R';
        }
        s[c++]='\0';
        printf("%s\n",s);
    }
    return 0;
}