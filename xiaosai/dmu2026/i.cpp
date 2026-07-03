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
int t,v,c;
ll p,q;
char s[N];
int main(){
    sci(t);
    while(t--){
        scanf("%s",s);
        p=q=1;
        c=strlen(s);
        reverse(s,s+c);
        rep(i,0,c-1){
            if(s[i]=='L')q+=p;
            else p+=q;
            //if(p<q)q-=p,s[c++]='L';
            //else p-=q,s[c++]='R';
        }
        printf("%lld %lld\n",p,q);
    }
    return 0;
}