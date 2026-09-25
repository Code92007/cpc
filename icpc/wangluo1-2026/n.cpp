#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2e6+10,INF=0x3f3f3f3f;
struct BIT{
	int n;
    vector<int>tr;
	void init(int _n){
        n=_n;
        tr.resize(n+1);
        fill(tr.begin(),tr.end(),-INF);
	}
	void upd(int x,int v){
		for(int i=x;i<=n;i+=i&-i)
		tr[i]=max(tr[i],v);
	}
	int ask(int x){
		int ans=-INF; 
		for(int i=x;i;i-=i&-i)
		ans=max(ans,tr[i]);
		return ans;
	}
}trg[M],trb[M];
int n,r,g,b,rg[N],rb[N];
vector<int>x[M],y[M];
int main(){
    scanf("%d",&n);
    rg[0]=rb[0]=n;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&r,&g,&b);
        rg[i]=rg[i-1]+r-g;
        rb[i]=rb[i-1]+r-b;
        x[rg[i]].push_back(rb[i]);
        y[rb[i]].push_back(rg[i]);
    }
    for(int i=0;i<=2*n;++i){
        trg[i].init(x[i].size());
        trb[i].init(y[i].size());
        sort(x[i].begin(),x[i].end());
        sort(y[i].begin(),y[i].end());
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        int tmp=ans;
        if(rg[i]>=n && rb[i]>=n)tmp=i;
        auto &vec1=x[rg[i]];
        int p1=lower_bound(vec1.begin(),vec1.end(),rb[i])-vec1.begin()+1;
        int w1=trg[rg[i]].ask(p1);
        tmp=max(tmp,i+w1);
        auto &vec2=y[rb[i]];
        int p2=lower_bound(vec2.begin(),vec2.end(),rg[i])-vec2.begin()+1;
        int w2=trb[rb[i]].ask(p2);
        tmp=max(tmp,i+w2);
        trg[rg[i]].upd(p1,tmp-i);
        trb[rb[i]].upd(p2,tmp-i);
        ans=tmp;
    }
    printf("%d\n",ans);
    return 0;
}
