#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e6+5;
ll n,a[MAXN],b[MAXN];
ll ans[MAXN],pre[MAXN],suf[MAXN];
int stk[MAXN],top;
ll sum;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
    }
	int p=max_element(a+1,a+n+1)-a;
	for(int i=1;i<=n;i++){
        b[(i-p+n-1)%n+1]=a[i];//把最大值扔到序列最后 i的答案被存在了(i-p+n-1)%n+1 即p的答案被存在了n
    }
	for(int i=0;i<=n+1;i++){
        pre[i]=suf[i]=0;
    }
	top=sum=0;
    stk[top=0]=0;
	for(int i=1;i<n;i++){
		while(top&&b[stk[top]]<b[i]){//考虑p=i时，min(max1,max2=最大值)中的max1在哪些位置j上有贡献
			sum-=b[stk[top]]*(stk[top]-stk[top-1]);
			top--;
		}
		sum+=b[i]*(i-stk[top]);
		stk[++top]=i;
		pre[i]=sum;
	}
	top=sum=0;
    stk[top=0]=n;
	for(int i=n-1;i>=1;i--){
		while(top&&b[stk[top]]<b[i]){
			sum-=b[stk[top]]*(stk[top-1]-stk[top]);
			top--;
		}
		sum+=b[i]*(stk[top]-i);
		stk[++top]=i;
		suf[i]=sum;
	}
	// for(int i=1;i<=n;i++) cerr<<b[i]<<" \n"[i==n];
	for(int i=1;i<=n;i++){
        ans[i]=pre[i-1]+suf[i];
    }
	for(int i=1;i<=n;i++){
        cout<<ans[(i-p+n-1)%n+1]<<" \n"[i==n];
    }
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int T;
    cin>>T;
	while(T--){
        solve();
    }
	return 0;
}
