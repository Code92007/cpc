#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
typedef double db;
#define rep(x,l,r) for(int x=l;x<=r;x++)
#define per(x,r,l) for(int x=r;x>=l;x--)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

const int MOD=998244353,INF=1e9;
const ll LNF=1e18;
int power(int a,int k,int mod=MOD) {
    a%=mod,k%=mod-1; if(k<0) k+=mod-1;
    int res=1; while(k) {
        if(k&1) res=1ll*res*a%mod;
        a=1ll*a*a%mod; k>>=1;
    } return res;
}
void add(int &x,int y) {x=(x+y>=MOD?x+y-MOD:x+y);}
void sub(int &x,int y) {x=(x>=y?x-y:x-y+MOD);}
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void chkmax(int &x,int y) {x<y?x=y:0;}
void chkmin(int &x,int y) {x>y?x=y:0;}

const int N=3003000;

int fac[N],ifac[N];
void init() {
    int n=3000000;
    fac[0]=1; rep(i,1,n) fac[i]=1ll*fac[i-1]*i%MOD;
    ifac[n]=power(fac[n],-1);
    per(i,n,1) ifac[i-1]=1ll*ifac[i]*i%MOD;
}
int binom(int n,int m) {
    if(m<0||m>n) return 0;
    return 1ll*fac[n]*ifac[n-m]%MOD*ifac[m]%MOD;
}

int n;
char s[N];
int pre[N];
int c1[N];
int getval(int l,int r) {
    int ans=(pre[r]-1ll*pre[l-1]*power(2,r-l+1)%MOD+MOD)%MOD;
    return ans;
}
int getc1(int l,int r) {
    return c1[r]-c1[l-1];
}

int m;
int sa[N*2],rk[N*2],tx[N],tp[N];
int height[N];
void radixsort() {
    rep(i,0,m) tx[i]=0;
    rep(i,1,n) tx[rk[i]]++;
    rep(i,1,m) tx[i]+=tx[i-1];
    per(i,n,1) sa[tx[rk[tp[i]]]--]=tp[i];
}
void suffixsort() {
    m=127; rep(i,1,n) rk[i]=s[i],tp[i]=i;
    radixsort();
    for(int w=1,p=0;p<n;w<<=1,m=p) {
        p=0; rep(i,n-w+1,n) tp[++p]=i;
        rep(i,1,n) if(sa[i]>w) tp[++p]=sa[i]-w;
        radixsort();
        rep(i,1,n) tp[i]=rk[i];
        rk[sa[1]]=p=1;
        rep(i,2,n) {
            if(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w]) rk[sa[i]]=p;
            else rk[sa[i]]=++p;
        }
    }
    int k=0; rep(i,1,n) {
        if(rk[i]==1) continue;
        k=max(k-1,0);
        while(s[i+k]==s[sa[rk[i]-1]+k]) k++;
        height[rk[i]]=k;
    }
}
void clear() {
    rep(i,1,n*2) sa[i]=rk[i]=0;
    rep(i,1,n) tp[i]=tx[i]=0;
}

ll A,B,C,D;
void addpq(ll p,ll q,int i) {
    A^=p;
    B^=q;
    C^=p*i;
    D^=q*i;
}

int st[N][23];
void st_init() {
    rep(i,1,n) st[i][0]=i;
    rep(k,1,22) {
        rep(i,1,n+1-(1<<k)) {
            int x=st[i][k-1],y=st[i+(1<<(k-1))][k-1];
            if(rk[x]>rk[y]) st[i][k]=x;
            else st[i][k]=y;
        }
    }
}
int st_query(int l,int r) {
    int k=log2(r-l+1);
    int x=st[l][k],y=st[r+1-(1<<k)][k];
    if(rk[x]>rk[y]) return x;
    else return y;
}

int hi[N][23];
void hi_init() {
    rep(i,1,n) hi[i][0]=height[i];
    rep(k,1,22) {
        rep(i,1,n+1-(1<<k)) {
            hi[i][k]=min(hi[i][k-1],hi[i+(1<<(k-1))][k-1]);
        }
    }
}
int hi_query(int l,int r) {
    if(l==r) return 1e9;
    l++;
    int k=int(log2(r-l+1));
    return min(hi[l][k],hi[r+1-(1<<k)][k]);
}

int find(int x,int len) {
    int l=1,r=x-1,ans=x;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(hi_query(mid,x)>=len) r=mid-1,ans=mid;
        else l=mid+1;
    }
    return ans;
}

int ctag[N];
int ctag_query(int l,int r) {
    return ctag[r]-ctag[l-1];
}

void solve() {
    A=B=C=D=0;
    scanf("%s",s+1),n=strlen(s+1);
    int tag=0;
    rep(i,1,n) if(s[i]=='1') tag=1;
    if(!tag) {
        rep(i,1,n) {
            int p=0,q=binom(n-1,i-1);
            addpq(p,q,i);
        }
    } else {
        pre[0]=0;
        rep(i,1,n) {
            pre[i]=(2ll*pre[i-1]+s[i]-'0')%MOD;
            c1[i]=(s[i]-'0')+c1[i-1];
        }

        int CC=c1[n];
        suffixsort();
        st_init(),hi_init();
        
        int fi=n;
        per(i,n,1) if(s[i]=='1') fi=i;
        rep(i,1,fi) {
            int p=pre[n],q=binom(fi-1,i-1);
            printf("i:%d p:%d q:%d\n",i,p,q);
            addpq(p,q,i);
        }

        rep(i,1,n) ctag[i]=0;
        rep(i,fi,n) ctag[rk[i]]=1;
        rep(i,1,n) ctag[i]+=ctag[i-1];

        rep(i,fi+1,n-1) {
            int len=n-i; // already -1   !!!
            // fi -> i
            int pos=st_query(fi,i);
            int RK=rk[pos];
            int PRK=find(RK,len);
            int p=getval(pos,pos+len);
            if(getc1(pos,pos+len)%2!=CC%2) {
                if(s[pos+len]=='1') sub(p,1);
                else add(p,1);
            }
            int q=ctag_query(PRK,RK);
            if(rk[i+1]>=PRK&&rk[i+1]<=RK) q--;
            printf("i:%d p:%d q:%d PRK:%d RK:%d\n",i,p,q,PRK,RK);
            addpq(p,q,i);
        }
        if(n!=fi) {
            // n
            int p=CC%2;
            int q=1;
            addpq(p,q,n);
        }
        clear();
    }
    printf("%lld %lld %lld %lld\n",A,B,C,D);
    // return;
}

int main() {
    init();
    int t; scanf("%d",&t); while(t--) solve();
    return 0;
}