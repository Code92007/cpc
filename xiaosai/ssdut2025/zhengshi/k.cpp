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
const int N=2e4+10;
int t,l,r;
char s[N];
int main(){
    sci(t);
    while(t--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        sci(l),sci(r);
        int ans=0;
        rep(j,l,r){
            bool first=false,combo;
            rep(i,1,j-1){//前i 后j-i n-(j-i)+1
                int suf_first=n-(j-i)+1;
                if(s[i]==s[suf_first]){
                    if(!first || !combo){
                        ans++;
                        first=true;   
                    }
                    combo=true;
                }
                if(s[i+1]!=s[suf_first])combo=false;
            }
        }
        pte(ans);
    }
    return 0;
}
/*
oiiaiioooooiaii
6 6
oiiai+i
oi iaii

*/