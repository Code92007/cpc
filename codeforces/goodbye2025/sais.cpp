#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int N=3e6+10,mod=998244353;

int Finv[N],fac[N],inv[N];
int modpow(int x,int n,int mod){
	int res=1;
	for(;n;x=1ll*x*x%mod,n>>=1)
	if(n&1)res=1ll*res*x%mod;
	return res;
}
void init(int n){ //n<N
    inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=Finv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod,Finv[i]=1ll*Finv[i-1]*inv[i]%mod;
}
int C(int n,int m){
	if(m<0||m>n)return 0;
	return 1ll*fac[n]*Finv[n-m]%mod*Finv[m]%mod;
}

// SA-IS 算法实现
struct SAIS {
    static const int maxn=3e6+10;
    static const int MAXC=256;
    
    int n, *s;
    int sa[maxn], rk[maxn], ht[maxn], tmp[maxn], c[maxn];
    bool t[maxn]; // t[i]: true if s[i..] is S-type, false if L-type
    int *x, *y, cnt[MAXC];

    void init_sa() {
        x = rk; y = tmp;
    }

    void radix_sort() {
        for(int i=0; i<256; i++) cnt[i]=0;
        for(int i=0; i<n; i++) cnt[(unsigned char)s[i]]++;
        for(int i=1; i<256; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sa[--cnt[(unsigned char)s[i]]]=i;
    }

    void sais(int n, int K) {
        this->n = n;
        
        // 判断S/L类型
        t[n-1] = true; // 最后一个字符是S-type
        for(int i=n-2; i>=0; i--) {
            if(s[i]<s[i+1]) t[i]=true;
            else if(s[i]>s[i+1]) t[i]=false;
            else t[i]=t[i+1];
        }
        
        // 初始化
        init_sa();
        radix_sort();
        
        x[sa[0]] = 0;
        int p = 1;
        for(int i=1; i<n; i++) {
            if(s[sa[i-1]]!=s[sa[i]] || t[sa[i-1]]!=t[sa[i]]) p++;
            x[sa[i]] = p-1;
        }
        
        if(p == n) {
            for(int i=0; i<n; i++) sa[x[i]]=i;
            return;
        }
        
        int m = n;
        n = (n+1)>>1;
        
        for(int d=1,i=0; i<m; i++) {
            if(i<n) c[i]=x[i*2+1];
        }
        
        sais_recursive(c, n, p);
        
        // 扩展
        for(int i=m-2; i>=0; i--) {
            if(i & 1) y[i>>1] = sa[i>>1];
            else y[((i>>1)+n)] = sa[i>>1];
        }
        copy(y, y+m, sa);
    }
    
    void sais_recursive(int *s, int n, int K) {
        if(n==1) {
            sa[0]=0;
            return;
        }
        
        t[n-1]=true;
        for(int i=n-2; i>=0; i--) {
            if(s[i]<s[i+1]) t[i]=true;
            else if(s[i]>s[i+1]) t[i]=false;
            else t[i]=t[i+1];
        }
        
        memset(cnt, 0, K*sizeof(int));
        for(int i=0; i<n; i++) cnt[s[i]]++;
        for(int i=1; i<K; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) tmp[--cnt[s[i]]]=i;
        
        x[tmp[0]]=0;
        int p=1;
        for(int i=1; i<n; i++) {
            if(s[tmp[i-1]]!=s[tmp[i]] || t[tmp[i-1]]!=t[tmp[i]]) p++;
            x[tmp[i]]=p-1;
        }
        
        if(p==n) {
            for(int i=0; i<n; i++) sa[x[i]]=i;
            return;
        }
        
        int m=n;
        n=(n+1)>>1;
        for(int d=1,i=0; i<m; i++) {
            if(i&1) y[i>>1]=x[i];
        }
        
        sais_recursive(y, n, p);
        
        for(int i=m-2; i>=0; i--) {
            if(i&1) y[i>>1]=sa[i>>1];
            else y[((i>>1)+n)]=sa[i>>1];
        }
        copy(y, y+m, sa);
    }

    void build_sa(int *str, int len) {
        s = str;
        sais(len, 256);
        
        // 计算rank和height
        rk[sa[0]] = 0;
        for(int i=1; i<len; i++) {
            rk[sa[i]] = rk[sa[i-1]];
            bool flag = false;
            for(int j=0; j<len; j++) {
                if(s[sa[i-1]+j] != s[sa[i]+j]) {
                    flag = true;
                    break;
                }
                if(sa[i-1]+j >= len-1 || sa[i]+j >= len-1) break;
            }
            if(flag) rk[sa[i]]++;
        }
        
        // 计算height数组
        for(int i=1,h=0; i<len; i++) {
            if(h) h--;
            int j=sa[rk[i]-1];
            while(i+h<len && j+h<len && s[i+h]==s[j+h]) h++;
            ht[rk[i]]=h;
        }
    }
};

struct SuffixArray{
    static const int maxn=3e6+10,bs=2;

    int suf[maxn];
    int pw[maxn],hs[maxn];
    int dp[maxn][23],lg[maxn];
    int sum[maxn];

    char s[maxn];
    typedef long long ll;
    int n,rk[maxn],sa[maxn],ht[maxn];
    
    SAIS sa_builder;
    
    void PR(){
        string p(s+1);
        for(int i=1;i<=n;++i)
        printf("Rank[%d]:%d\n",i,rk[i]);
        for(int i=1;i<=n;++i)
        {
            printf("sa[%d]:%d ",i,sa[i]);
            cout<<p.substr(sa[i])<<endl;
        }
        for(int i=1;i<=n;++i)
        printf("ht[%d]:%d\n",i,ht[i]);
    }
    
    inline void ST(int n){
        for(int i=1;i<=n;++i)dp[i][0]=ht[i];
        for(int j=1;(1<<j)<=n;++j){
            for(int i=1;i+(1<<j)-1<=n;++i){
                dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
            }
        } 
    }
    
    void init(){
        lg[1]=0;
        pw[0]=1;
        pw[1]=bs;
        for(int i=2;i<maxn;++i){
            lg[i]=lg[i/2]+1;
            pw[i]=1ll*pw[i-1]*bs%mod;
        }
    }
    
    int hash(int l,int r){
        return (hs[r]-1ll*hs[l-1]*pw[r-l+1]%mod+mod)%mod;
    }
    
    int Xor(int l,int r){
        if(l>r)return 0;
        return sum[r]^sum[l-1];
    }
    
    int RMQ(int l,int r){
        int k=lg[r-l+1];
        return min(dp[l][k],dp[r-(1<<k)+1][k]); 
    }
    
    P cal(int p,int len){
        int L=p+1,R=p;
        {
            int l=1,r=p;
            while(l<=r){
                int mid=(l+r)/2;
                if(RMQ(mid,p)>=len)r=mid-1;
                else l=mid+1;
            }
            L=l;
        }
        {
            int l=p+1,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                if(RMQ(p+1,mid)>=len)l=mid+1;
                else r=mid-1;
            }
            R=r;
        }
        return P(L,R);
    }
    
    void solve(){
        scanf("%s",s+1);
        n=strlen(s+1);
        int left=0;
        sum[0]=hs[0]=0;
        for(int i=1;i<=n;++i){
            int v=s[i]-'0';
            if(v==1 && !left)left=i;
            sum[i]=sum[i-1]^v;
            hs[i]=(1ll*hs[i-1]*bs+v)%mod;
        }
        
        // 使用SA-IS构造后缀数组
        int str[maxn];
        for(int i=1; i<=n; i++) {
            str[i-1] = s[i] - '0';
        }
        sa_builder.build_sa(str, n);
        
        // 转换到1-indexed
        for(int i=0; i<n; i++) {
            sa[i+1] = sa_builder.sa[i] + 1;
            rk[i+1] = sa_builder.rk[i];
            if(i>0) ht[i+1] = sa_builder.ht[i];
        }
        rk[0] = ht[0] = 0;
        
        suf[n]=sa[n];
        for(int i=n-1;i>=1;--i){
            suf[i]=min(suf[i+1],sa[i]);
        }
        
        ST(n);
        
        ll a=0,b=0,c=0,d=0;
        int now=n;
        for(int k=n;k>=1;--k){
            int ans,cnt;
            int l=1,r=n,len=n-k+1;
            while(now>=1 && suf[now]+len-1>n)now--;
            int p=now,st=sa[p],ed=sa[p]+len-1;
            if(s[st]=='1'){
                auto [L,R]=cal(p,len);
                ans=hash(st,ed);
                int one=Xor(st,ed);
                if(one!=sum[n]) {
                    if(s[ed]=='1')ans=(ans-1+mod)%mod;
                    else ans=(ans+1)%mod;
                }
                if(k<n){
                    cnt=R-L+2;
                    int w=s[ed]-'0';
                    if(w==1){
                        if(L-2>=1 && ht[L-1]>=len-1 && sa[L-2]+len-1<=n){
                            int ed2=sa[L-2]+len-1,lw=s[ed2]-'0';
                            if(lw==0){
                                auto [L2,R2]=cal(L-2,len);
                                cnt+=R2-L2+2;
                            }
                        }
                    }
                    else{
                        if(R+1<=n && ht[R+1]>=len-1 && sa[R+1]+len-1<=n){
                            int ed2=sa[R+1]+len-1,rw=s[ed2]-'0';
                            if(rw==1){
                                auto [L2,R2]=cal(R+1,len);
                                cnt+=R2-L2+2;
                            }
                        }
                    }
                }
                else{
                    cnt=1;
                }
            }
            else{
                if(!left){
                    ans=0,cnt=C(n-1,k-1);
                }
                else{
                    ans=hs[n],cnt=C(left-1,k-1);
                }
            }
            a^=ans,b^=cnt,c^=1ll*ans*k,d^=1ll*cnt*k;
        }
        printf("%lld %lld %lld %lld\n",a,b,c,d);
        for(int i=0;i<n;i++) sa_builder.sa[i]=0;
    }
}sa;

int main(){
    init(N-5);
    sa.init();
    int t;
    scanf("%d",&t);
    while(t--){
        sa.solve();
    }
    return 0;
}
