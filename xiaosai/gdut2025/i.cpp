#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
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
const int N=1e6+10,mod=1e9+7;
int t,n,a,c,m,ac,cm,acm;
char s[N];
void add(int &x,int y){
    x=(x+y)%mod;
}
int main(){
    sci(t);
    while(t--){
        scanf("%s",s+1);
        n=strlen(s+1);
        a=ac=acm=m=cm=0;
        rep(i,1,n){
            char x=s[i];
            if('a'<=x && x<='m'){
                if(x=='a')add(acm,cm),add(ac,c),add(a,1);
                else if(x=='c')add(cm,m),add(c,1);
                else add(m,1);
            }
            else{
                if(x=='A')add(a,1);
                else if(x=='C')add(ac,a),add(c,1);
                else add(acm,ac),add(cm,c),add(m,1);
            }
            printf("%d%c",acm," \n"[i==n]);
        }
    }
    return 0;
}