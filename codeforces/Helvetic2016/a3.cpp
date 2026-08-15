//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
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
using namespace std;
int t,n,r,v;
int main(){
    sci(t);
    while(t--){
        sci(n),sci(r);
        r--;
        int sum=0;
        rep(i,1,n-1){
            sci(v);
            sum+=v;
        }
        sum%=n;
        int ans=(r-sum)%n;
        if(ans<=0)ans+=n;
        printf("%d\n",ans);
    }
    return 0;
}