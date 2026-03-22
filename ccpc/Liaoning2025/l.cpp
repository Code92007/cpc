#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
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
	//Finv[n]=modpow(fac[n],mod-2,mod);
	//for(int i=n-1;i>=1;--i)Finv[i]=1ll*Finv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	if(m<0||m>n)return 0;
	return 1ll*fac[n]*Finv[n-m]%mod*Finv[m]%mod;
}

struct SuffixArray{
    static const int maxn=3e6+10,bs=2;

    int suf[maxn];
    int pw[maxn],hs[maxn];
    int dp[maxn][23],lg[maxn];
    int sum[maxn];

    char s[maxn];
    typedef long long ll;
    int cnt[maxn],mx,n,rk[maxn],sa[maxn],tmp[maxn],ht[maxn];
    inline void base_sort(){
        memset(cnt,0,sizeof(*cnt)*(mx+1));
        for(int i=1;i<=n;++i)++cnt[rk[i]];
        for(int i=1;i<=mx;++i)cnt[i]+=cnt[i-1];
        for(int i=n;i;--i)sa[cnt[rk[tmp[i]]]--]=tmp[i];
    }
    inline void suffix_sort(){
        mx=0;
        for(int i=1;i<=n;++i)mx=max(mx,rk[i]=s[i]),tmp[i]=i;
        base_sort();
        for(int len=1,dif=0;dif<n;len<<=1,mx=dif){
            int p=0;
            for(int i=n-len+1;i<=n;++i)tmp[++p]=i;
            for(int i=1;i<=n;++i)
                if(sa[i]>len)
                    tmp[++p]=sa[i]-len;
            base_sort();
            swap(rk,tmp);
            rk[sa[1]]=dif=1;
            for(int i=2;i<=n;++i){
                if(tmp[sa[i-1]]!=tmp[sa[i]]||tmp[sa[i-1]+len]!=tmp[sa[i]+len])++dif;
                rk[sa[i]]=dif;
            }
        }
    }
    inline void calc_ht(){
        for(int i=1,h=0;i<=n;++i){
            if(h)--h;
            int j=sa[rk[i]-1];
            while(s[i+h]==s[j+h])++h;
            ht[rk[i]]=h;
        }
    }
    // rank、sa、height下标均为[1,n]
    inline void PR(){
        string p(s+1);
        for(int i=1;i<=n;++i)
        printf("Rank[%d]:%d\n",i,rk[i]);
        for(int i=1;i<=n;++i)
        {
            printf("sa[%d]:%d ",i,sa[i]);
            cout<<p.substr(sa[i]-1)<<endl;
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
        for(int i=1;i<=n;++i){
            int v=s[i]-'0';
            if(v==1 && !left)left=i;
            sum[i]=sum[i-1]^v;
            hs[i]=(1ll*hs[i-1]*bs+v)%mod;
            //printf("i:%d hs:%d\n",i,hs[i]);
        }
        suffix_sort();
	    calc_ht();
        ST(n);
        suf[n]=sa[n];
        for(int i=n-1;i>=1;--i){
            suf[i]=min(suf[i+1],sa[i]);
        }
        ll a=0,b=0,c=0,d=0;
        int now=n;
        for(int k=n;k>=1;--k){
            int ans,cnt;
            int l=1,r=n,len=n-k+1;
            while(now>=1 && suf[now]+len-1>n)now--;
            //sa[p]开头的长为len的
            //[sa[p],sa[p]+len-1]
            int p=now,st=sa[p],ed=sa[p]+len-1;
            if(s[st]=='1'){
                auto [L,R]=cal(p,len);
                //printf("k:%d L:%d R:%d st:%d ed:%d hash:%d\n",k,L,R,st,ed,hash(st,ed));
                ans=hash(st,ed)^Xor(1,st-1)^Xor(ed+1,n);
                //(11,0) (10,1)
                if(k<n){//k=n只有一种方案
                    cnt=R-L+2;
                    int w=s[ed]-'0';
                    if(w==1){
                        //printf("L-2:%d ht:%d sa:%d\n",L-2,ht[L-1],sa[L-2]);
                        if(L-2>=1 && ht[L-1]>=len-1 && sa[L-2]+len-1<=n){
                            int ed2=sa[L-2]+len-1,lw=s[ed2]-'0';
                            if(lw==0){
                                auto [L2,R2]=cal(L-2,len);
                                //printf("k:%d L2:%d R2:%d addcntL:%d\n",k,L2,R2,R2-L2+2);
                                cnt+=R2-L2+2;
                            }
                        }
                    }
                    else{
                        //printf("R+1:%d ht:%d sa:%d\n",R+1,ht[R+1],sa[R+1]);
                        if(R+1<=n && ht[R+1]>=len-1 && sa[R+1]+len-1<=n){
                            int ed2=sa[R+1]+len-1,rw=s[ed2]-'0';
                            if(rw==1){
                                auto [L2,R2]=cal(R+1,len);
                                //printf("k:%d L2:%d R2:%d addcntR:%d\n",k,L2,R2,R2-L2+2);
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
                    ans=hash(left,n),cnt=C(left-2,k-1);
                }
            }
            ans=(ans%mod+mod)%mod,cnt%=mod;
            //printf("k:%d ans:%d cnt:%d ans*k:%lld cnt*k:%lld\n",k,ans,cnt,1ll*ans*k,1ll*cnt*k);
            a^=ans,b^=cnt,c^=1ll*ans*k,d^=1ll*cnt*k;
        }
        printf("%lld %lld %lld %lld\n",a,b,c,d);
        //PR();
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
/*
00010
*/