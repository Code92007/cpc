#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int t,n,a[N],dp[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        dp[n]=1;
        for(int i=n-1;i>=1;--i){
            if(a[i]==a[i+1])dp[i]=dp[i+1]+1;
            else dp[i]=1;
        }
        ll ans=(a[n]==0);
        for(int i=1;i<n;++i){
            if(a[i]==1)ans+=(a[i+1]==-1);
            else if(a[i]==-1)ans+=(a[i+1]==1);
            else{
                ans++;
                if(a[i+1])ans+=dp[i+1];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}