//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,int> P;
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
typedef array<ll,6> A;
const int N=8e5+10,M=2e5+10;
struct segtree{
	int n;
	struct node{
        int l,r;
        P rk[2];//(w,c)
        node(){
            rk[0]=rk[1]=P(-1,0);
        }
    }e[N<<2];
	#define l(p) e[p].l
	#define r(p) e[p].r
    node merge(node a, node b){
        vector<P>x;
        rep(i,0,1){
            x.pb(a.rk[i]);
            x.pb(b.rk[i]);
        }
        sort(x.begin(),x.end(),greater<P>());
        node y;
        y.l=min(a.l,b.l);
        y.r=max(a.r,b.r);
        y.rk[0]=x[0];
        rep(i,1,3){
            if(x[i].se!=y.rk[0].se){
                y.rk[1]=x[i];
                break;
            }
        }
        return y;
    }
	void up(int p){
        e[p]=merge(e[p<<1],e[p<<1|1]);
    }
	void bld(int p,int l,int r){
		l(p)=l;r(p)=r;
		if(l==r){
            e[p].rk[0]=e[p].rk[1]=P(-1,0);
            return;
        }
		int mid=l+r>>1;
		bld(p<<1,l,mid);
        bld(p<<1|1,mid+1,r);
		up(p);
	}
	void init(int _n){n=_n;bld(1,0,n);}
	void chg(int p,int x,P v){
		if(l(p)==r(p)){
            //printf("v:(%lld,%lld)\n",v.fi,v.se);
            if(v.fi>e[p].rk[0].fi){
                if(v.se==e[p].rk[0].se)e[p].rk[0]=max(e[p].rk[0],v);
                else{
                    swap(e[p].rk[0],e[p].rk[1]);
                    e[p].rk[0]=v;
                }
            }
            else if(v.fi>e[p].rk[1].fi){
                if(v.se!=e[p].rk[0].se)e[p].rk[1]=v;
            }
            return;
        }
		int mid=l(p)+r(p)>>1;
		chg(p<<1|(x>mid),x,v);
		up(p);
	}
    void del(int p,int x){
		if(l(p)==r(p)){
            e[p].rk[0]=e[p].rk[1]=P(-1,0);
            return;
        }
		int mid=l(p)+r(p)>>1;
		del(p<<1|(x>mid),x);
		up(p);
	}
	node ask(int p,int ql,int qr){
		if(ql<=l(p)&&r(p)<=qr)return e[p];
		int mid=l(p)+r(p)>>1;
        node res;
		if(ql<=mid)res=merge(res,ask(p<<1,ql,qr));
		if(qr>mid)res=merge(res,ask(p<<1|1,ql,qr));
		return res;
    }
}seg;
int q,C,x0,k,x[N],c;
vector<A>a[M],ok,ok2;
int f(int v){
    return lower_bound(x,x+c,v)-x;
}
int main(){
    sci(q),sci(C),sci(x0);
    x[c++]=x0;
    rep(i,1,q){
        sci(k);
        rep(j,0,k-1){
            A z;
            rep(j,0,5){
                scanf("%lld",&z[j]);
                if(j<=3)x[c++]=z[j];
                //printf("j:%d zj:%lld\n",j,z[j]);
            }
            a[i].pb(z);
        }
    }
    sort(x,x+c);
    c=unique(x,x+c)-x;
    x0=f(x0);
    seg.init(c);
    seg.chg(1,x0,P(0,0));
    ok.push_back({x0,x0,x0,x0,0,0});
    rep(i,1,q){
        if(ok.empty())break;
        for(auto &w:a[i]){
            rep(j,0,3)w[j]=f(w[j]);
        }
        sort(ok.begin(),ok.end(),[&](A x, A y){
            return x[2]<y[2];
        });
        sort(a[i].begin(),a[i].end(),[&](A x, A y){
            return x[1]<y[1];
        });
        int sz=ok.size(),cur=0;
        ok2.clear();
        for(auto &w:a[i]){
            while(cur<sz && ok[cur][2]<=w[1]){
                A &z=ok[cur];
                //printf("z5:%lld z4:%lld\n",z[5],z[4]);
                seg.chg(1,z[3],P(z[5],z[4]));
                cur++;
            }
            auto z=seg.ask(1,w[0],c);
            int id=0;
            if(z.rk[0].se==w[4])id=1;
            if(z.rk[id].fi<0)continue;
            //printf("id:%d val:%lld\n",id,z.rk[id].fi);
            //printf("w5:%lld\n",w[5]);
            w[5]+=z.rk[id].fi;
            //printf("w5:%lld\n",w[5]);
            ok2.push_back(w);
        }
        per(j,cur-1,0){
            auto w=ok[j];
            seg.del(1,w[3]);
        }
        ok.swap(ok2);
    }
    if(ok.empty())puts("-1");
    else{
        ll ans=0;
        for(auto &w:ok){
            ans=max(ans,w[5]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}