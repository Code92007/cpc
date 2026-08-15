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
const int N=2e5+10,M=8e5+10,S=16e5+10;
int n,m,c,k,a[N],x[S],now[S],cnt,cnt2;
int q,pos[N],w[N],mul[S];
struct Bit{
    int n,tr[S];
    void init(int _n){
        n=_n;
        memset(tr,0,(n+1)*sizeof(*tr));
    }
    void add(int x,int v){
        x++;
        for(int i=x;i<=n;i+=i&-i)
            tr[i]+=v;
    }
    int sum(int x){
        x++;
        int ans=0;
        for(int i=x;i;i-=i&-i)
            ans+=tr[i];
        return ans;
    }
}tr;
struct segtree{
    int n;
    struct node{int l,r,c;ll s,k,b;}e[S<<2];
    #define l(p) e[p].l
    #define r(p) e[p].r
    #define s(p) e[p].s
    #define c(p) e[p].c
    #define k(p) e[p].k
    #define b(p) e[p].b
    void up(int p){
        s(p)=s(p<<1)+s(p<<1|1);
        k(p)=k(p<<1)+k(p<<1|1);
        b(p)=b(p<<1)+b(p<<1|1);
    }
    void bld(int p,int l,int r){
        l(p)=l;r(p)=r;
        c(p)=-1;
        if(l==r){
            k(p)=mul[l];
            b(p)=-1ll*mul[l]*x[l];
            s(p)=0;
            return;
        }
        int mid=l+r>>1;
        bld(p<<1,l,mid);bld(p<<1|1,mid+1,r);
        up(p);
    }
    void psd(int p){
        if(~c(p)){
            s(p<<1)=k(p<<1)*c(p)+b(p<<1);
            c(p<<1)=c(p);
            s(p<<1|1)=k(p<<1|1)*c(p)+b(p<<1|1);
            c(p<<1|1)=c(p);
            c(p)=-1;
        }
    }
    void init(int _n){n=_n;bld(1,0,n);}
    void add(int p,int z,ll w){
        if(l(p)==r(p)){
            int y=l(p);
            //k(p)=mul[y];
            //b(p)=-1ll*mul[y]*x[y];
            s(p)=k(p)*w+b(p);
            return;
        }
        int mid=l(p)+r(p)>>1;
        psd(p);
        add(p<<1|(z>mid),z,w);
        up(p);
    }
    void del(int p,int z){
        if(l(p)==r(p)){
            s(p)=0;
            c(p)=-1;
            return;
        }
        int mid=l(p)+r(p)>>1;
        psd(p);
        del(p<<1|(z>mid),z);
        up(p);
    }
    void cov(int p,int ql,int qr,ll v){
        if(ql>qr)return;
        if(ql<=l(p)&&r(p)<=qr){
            s(p)=1ll*k(p)*v+b(p);
            c(p)=v;
            return;
        }
        psd(p);
        int mid=l(p)+r(p)>>1;
        if(ql<=mid)cov(p<<1,ql,qr,v);
        if(qr>mid)cov(p<<1|1,ql,qr,v);
        up(p);
    }
    ll cnt(int p,int ql,int qr){
        if(ql<=l(p)&&r(p)<=qr)return s(p);
        int mid=l(p)+r(p)>>1;
        ll res=0;
        psd(p);
        if(ql<=mid)res+=cnt(p<<1,ql,qr);
        if(qr>mid)res+=cnt(p<<1|1,ql,qr);
        return res;
    }
}seg;
int cal(int l,int r){
    return tr.sum(r)-tr.sum(l-1);
}
bool ok(){
    return cal(0,cnt-1)==cnt;
}
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
void extgcd(ll a,ll b,ll &x,ll &y){
    ll d=a;
    if(b)extgcd(b,a%b,y,x),y-=(a/b)*x;
    else x=1,y=0;
}
void init(){
    if(c==0){
        rep(i,0,cnt-1){
            if(x[i]==0)mul[i]=k;
        }
        return;
    }
    //(c*x+a[i])%m=0,x<K
    ll g=gcd(c,m),gc=c/g,mc=m/g,p,q;
    //x=v*(gc)^-1(mod mc)
    //printf("gc:%lld mc:%lld\n",gc,mc);
    extgcd(gc,mc,p,q);
    //ax+by=1
    p=(p%mc+mc)%mc;
    //printf("inv:%lld\n",p);
    rep(i,0,cnt-1){
        ll v=x[i];
        v=(m-v)%m;
        if(v%g)continue;
        //printf("i:%d v:%lld\n",i,v);
        //cx=-v(mod m) x+1=0(mod 3) x=2(mod 3)
        v/=g;
        ll w=(1ll*v*p)%mc;
        ll r=k-1;
        if(w>r)continue;
        mul[i]=max(0ll,(r-w)/mc+1);
        //printf("i:%d mul:%lld\n",i,mul[i]);
    }
}
void add(int p){
    now[p]++;
    if(now[p]>1){
        return;
    }
    //printf("p:%d\n",p);
    tr.add(p,1);
    tr.add(p+cnt,1);
    if(ok()){
        //seg.add(1,p,x[p]);
        return;
    }
    int l=p+1,r=cnt2-1;
    //p的mex
    while(l<=r){
        int mid=(l+r)/2,len=mid-(p+1)+1;
        if(cal(p+1,mid)==len)l=mid+1;
        else r=mid-1;
    }
    ll w=x[l],rw=w;
    if(l<cnt)rw+=m;
    seg.add(1,p,w);
    //printf("l:%d p:%d w:%lld rw:%lld\n",l,p,w,rw);
    int rp=p+cnt;
    {
        int l=p,r=rp-1;
        while(l<=r){
            int mid=(l+r)/2,len=(rp-1)-mid+1;
            if(cal(mid,rp-1)==len)r=mid-1;
            else l=mid+1;
        }
        //[l,cnt-1][0,p-1] mex↑
        //printf("l:%d rp:%d cnt:%d cnt2:%d\n",l,rp,cnt,cnt2);
        if(l<rp){
            if(l<cnt){
                seg.cov(1,l,cnt-1,rw);
                seg.cov(1,0,p-1,w);
            }
            else{
                seg.cov(1,l-cnt,p-1,w);
            }
        }
    }
}
void del(int p){
    now[p]--;
    if(now[p]>0){
        return;
    }
    tr.add(p,-1);
    tr.add(p+cnt,-1);
    seg.del(1,p);
    int rp=p+cnt;
    {
        int l=p,r=rp-1;
        while(l<=r){
            int mid=(l+r)/2,len=(rp-1)-mid+1;
            if(cal(mid,rp-1)==len)r=mid-1;
            else l=mid+1;
        }
        //[l,cnt-1][0,p-1] mex↑
        if(l<rp){
            if(l<cnt){
                seg.cov(1,l,cnt-1,x[p]+m);
                seg.cov(1,0,p-1,x[p]);
            }
            else{
                seg.cov(1,l-cnt,p-1,x[p]);
            }
        }
    }
}
ll ask(){
    if(ok())return 1ll*k*m;
    return seg.cnt(1,0,cnt-1);
}
int main(){
    sci(n),sci(m),sci(c),sci(k);
    rep(i,1,n){
        sci(a[i]);
        x[cnt++]=a[i];
        x[cnt++]=(a[i]+1)%m;
    }
    sci(q);
    rep(i,1,q){
        sci(pos[i]),sci(w[i]);
        x[cnt++]=w[i];
        x[cnt++]=(w[i]+1)%m;
    }
    sort(x,x+cnt);
    cnt=unique(x,x+cnt)-x;
    rep(i,0,cnt-1){
        x[i+cnt]=x[i]+m;
    }
    cnt2=2*cnt;
    init();
    tr.init(cnt2);
    seg.init(cnt2);
    //y=kx+b
    rep(i,1,n){
        a[i]=lower_bound(x,x+cnt,a[i])-x;
        add(a[i]);
        //printf("%lld\n",ask());
    }
    rep(i,1,q){
        w[i]=lower_bound(x,x+cnt,w[i])-x;
        int p=pos[i];
        del(a[p]);
        a[p]=w[i];
        add(a[p]);
        printf("%lld\n",ask());
    }
    return 0;
}