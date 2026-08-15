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
const int N=1e6+10;
int t,n,lg[N];
ll k;
ll sol(){
    if(n<=20){
        int up=1<<n;
        if(up<k)return -1;
    }
    int w=k;
    ll now=1;
    k--;
    //C(n,i)=C(n,i-1)
    vector<ll>ans;
    ans.pb(0);
    rep(i,1,n){
        now=1ll*now*(n-i+1)/i;
        ll v=min(now,1ll*k);
        k-=v;
        //printf("C(%d,%d):%lld kleft:%lld\n",n,i,now,k);
        rep(j,1,v){
            ans.pb(i);
        }
        if(!k)break;
    }
    ll res=0;
    reverse(ans.begin(),ans.end());
    per(j,w,1){
        //printf("j:%d lg:%d ans:%d\n",j,lg[j],ans[j-1]);
        res+=1ll*lg[j]*ans[j-1];
    }
    return res;
}
int main(){
    rep(i,1,N-5){
        lg[i]=lg[i/10]+1;
    }
    sci(t);
    while(t--){
        sci(n),sci(k);
        printf("%lld\n",sol());
    }
    return 0;
}