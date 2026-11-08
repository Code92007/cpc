#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
struct Bit{
	int n,tr[N];
	void init(int _n){
		n=_n;
		memset(tr,0,(n+1)*sizeof(*tr));
	}
	void ask(int x,int v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]+=v;
	}
	int sum(int x){
		int ans=0; 
		for(int i=x;i;i-=i&-i)
		ans+=tr[i];
		return ans;
	}
}tr;
int t,n,l[N],r[N];
vector<int>ask[N];
set<int>out0;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        out0.clear();
        tr.init(n);
        for(int i=1;i<=n;++i){
            ask[i].clear();
        }
        //统计对于[li,ri]内的点j，是否在ri时刻出度仍为0，仍为0后续的边就需要保留，否则可删掉
        for(int i=2;i<=n;++i){
            scanf("%d%d",&l[i],&r[i]);
            ask[r[i]].push_back(l[i]);
        }
        //在i时刻删掉区间[li,ri]出度仍为0的点
        ll ans=0;
        for(int i=1;i<=n;++i){
            if(i>1){
                auto it=out0.lower_bound(l[i]);
                while(it!=out0.end() && (*it)<=r[i]){
                    int p=*it;
                    tr.ask(p,-1);
                    it=out0.erase(it);
                }
            }
            out0.insert(i);
            tr.ask(i,1);
            for(auto &v:ask[i]){
                ans+=tr.sum(i)-tr.sum(v-1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}