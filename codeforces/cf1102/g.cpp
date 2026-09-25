#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5+5;
int n,a[MAXN];
vector<int> lose[MAXN];// g: win -> lose
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=n+1;i++) lose[i].clear();
	set<int> win;// the vertex for first-win (g)
	set<array<int,3>> intv;
	for(int i=0;i<=n+1;i++) win.insert(i);
	for(int i=0;i<=n;i++) intv.insert({1,i,i+1});
	for(int i=1;i<=n;i++) lose[n-i].push_back(i);
	for(int i=n;i>=1;i--){
		for(int j:lose[i]){
			win.erase(j);
			auto it=win.upper_bound(j);
			int r=*it;
			int l=*(--it);
			intv.erase({j-l,l,j});
			intv.erase({r-j,j,r});
			intv.insert({r-l,l,r});
		}
		while((--intv.end())->at(0)>=a[i]+2){
			auto [len,l,r]=*(--intv.end());
			for(int j=l+1;j+a[i]<r;j++){
				// f[i][j] = false
				if(i==1&&j==1){puts("2");return;}
				intv.erase({r-j+1,j-1,r});
				intv.insert({1,j-1,j});
				intv.insert({r-j,j,r});
				win.insert(j);
				if(i-j-1>=1) lose[i-j-1].push_back(j);
			}
		}
	}
    puts("1");
}
int main(){
	int T;
    scanf("%d",&T);
	while(T--)solve();
	return 0;
}
