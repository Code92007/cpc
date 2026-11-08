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
const int N=1e5+10,M=4e6+10,K=3e5+10;
int t,n,q,a[N],b[K],c,x;
vector<int>res;
int tr[M][2],cnt,num[M],ed[M];
void init(){
    cnt=0;
    memset(tr[0],0,sizeof tr[0]);
    num[0]=0;
    ed[0]=0;
}
void add(int x){
    int rt=0;
	for(int i=30;i>=0;--i){
        int v=x>>i&1;
		if(!tr[rt][v]){
            tr[rt][v]=++cnt;
            num[cnt]=0;
            memset(tr[cnt],0,sizeof tr[cnt]);
            ed[cnt]=0;
        }
		rt=tr[rt][v];
        num[rt]++;
	}
    ed[rt]++;
}
//cnt(x^y)<=mid
ll ask(int x,int mid){
    ll res=0;
    int rt=0;
    for(int i=30;i>=0;--i){
        int v=x>>i&1,w=mid>>i&1;
        if(w==1){
            if(tr[rt][v])res+=num[tr[rt][v]];
            rt=tr[rt][v^1];
        }
        else rt=tr[rt][v];
        if(!rt)break;
    }
    if(rt)res+=num[rt];
    return res;
}
void dfs(int i,int rt,int val,int x,int mid){
    if(val<mid && ed[rt]){
        rep(k,1,ed[rt]){
            b[++c]=val;
        }
    }
    if(i<0)return;
    int v=x>>i&1,w=mid>>i&1;
    rep(y,0,1){
        int nex=tr[rt][y];
        if(nex && num[nex]){
            int w=(val<<1)|(v^y);
            if(w<=mid)dfs(i-1,nex,w,x,mid);
        }
    }
}
bool ok(ll mid){
    ll res=0;
    rep(i,1,n){
        res+=ask(a[i],mid);
        if(res>=3ll*n)return 1;
    }
    res=(res-n)/2;
    return res>=n;
}
void sol(){
    init();
    rep(i,1,n){
        add(a[i]);
    }
    ll l=0,r=(1<<30)-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(ok(mid))r=mid-1;
        else l=mid+1;
    }
    rep(i,1,n){
        dfs(30,0,0,a[i],l);
    }
    while(c<3*n)b[++c]=l;
    sort(b+1,b+c+1);
    c=0;
    for(int i=n+1;i<=3*n;i+=2){
        b[++c]=b[i];
    }
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(q);
        rep(i,1,n){
            sci(a[i]);
        }
        sort(a+1,a+n+1);
        res.clear();
        res.pb(a[n]-a[1]);
        while(true){
            bool ok=1;
            c=0;
            sol();
            // rep(i,1,n){
            //     rep(j,i+1,n){
            //         b[++c]=a[i]^a[j];
            //     }
            // }
            // sort(b+1,b+c+1);
            //printf("k:%d\n",k);
            rep(i,1,n){
                ok&=(a[i]==b[i]);
                //printf("%d ",b[i]);
                a[i]=b[i];
            }
            //puts("");
            res.pb(a[n]-a[1]);
            if(ok)break;
        }
        while(q--){
            sci(x);
            x=min(x,SZ(res)-1);
            printf("%d\n",res[x]);
        }
    }
    return 0;
}