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
const int N=505;
int t,n;
char s[N],w[N];
int main(){
    sci(t);
    while(t--){
        sci(n);scanf("%s",w+1);
        scanf("%s",s+1);
        int ans=0;
        for(int i=1;i<=n+1-i;++i){
            int oth=n+1-i;
            if(i==oth){
                continue;
            }
            else{
                if(s[i]==s[oth])continue;
                int cnt=(s[i]!=w[1]) + (s[oth]!=w[1]);
                ans+=cnt;
            }
        }        
        pte(ans);
    }
    return 0;
}