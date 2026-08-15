//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int t;
ll n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        int p=63-__builtin_clzll(n);
        ll x=1ll<<p,ans=(x-1)/3,y;
        for(x/=2,y=x*3;x>0 && y<=n;x/=4,y+=3*x){
            ans+=min(n,(x-1)/2+y)-y+1;
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}