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
const int N=2e5+10;
int n,a[N],stk[N],c,l[N],r[N],f[N];
ll pre[N],suf[N],sum[N],ans[N];
/*
a a x b b b b l=3 r=5
1:1 2:2 3:3 4:3 5:3 6:2 7:1 
a a x a a l=3 r=3
1:1 2:2 3:3 4:2 5:1
x a a a
1:1 2:1 3:1 4:1
考虑二维差分 前缀 后缀 区间
a x a a a 
1:1 2:2 3:2 4:2 5:1
a x a
1:1 2:2 3:1
不妨l[i]<r[i]
[1,l[i]]每+1 数字+1
[l[i]+1,r[i]-1] 数字不变
[r[i],len]每+1 数字-1
*/
int main(){
    sci(n);
    rep(i,1,n){
        sci(a[i]);
        while(c && a[stk[c]]<=a[i]){
            c--;
        }
        l[i]=(!c?1:stk[c]+1);
        stk[++c]=i;
    }
    c=0;
    per(i,n,1){
        while(c && a[stk[c]]<a[i]){
            c--;
        }
        r[i]=(!c?n:stk[c]-1);
        stk[++c]=i;
    }
    rep(i,1,n){
        int len=r[i]-l[i]+1;
        //printf("i:%d l:%d r:%d\n",i,l[i],r[i]);
        if(len==1){
            ans[1]+=a[i];
        }
        else{
            l[i]=i-l[i]+1,r[i]=r[i]-i+1;
            //printf("i:%d l:%d r:%d\n",i,l[i],r[i]);
            if(l[i]>r[i])swap(l[i],r[i]);
            int dec=len-r[i]+1;
            if(l[i]==r[i]){
                pre[1]+=a[i];
                pre[l[i]+1]-=1ll*(l[i]+1)*a[i];
                pre[l[i]+2]+=1ll*l[i]*a[i];
                suf[len]+=a[i];
                suf[r[i]]-=1ll*dec*a[i];
                suf[r[i]-1]+=1ll*(dec-1)*a[i];
            }
            else{
                if(l[i]==1){
                    sum[1]+=a[i];
                    sum[len+1]-=a[i];
                }
                else{
                    pre[1]+=a[i];
                    pre[l[i]+1]-=1ll*(l[i]+1)*a[i];
                    pre[l[i]+2]+=1ll*l[i]*a[i];
                    suf[len]+=a[i];
                    suf[r[i]-1]-=1ll*(dec+1)*a[i];
                    suf[r[i]-2]+=1ll*dec*a[i];
                    sum[l[i]+1]+=a[i];
                    sum[r[i]]-=a[i];
                }
            }
        }
    }
    rep(i,1,n)sum[i]+=sum[i-1];
    rep(i,1,n)pre[i]+=pre[i-1];
    rep(i,1,n)pre[i]+=pre[i-1];
    per(i,n-1,1)suf[i]+=suf[i+1];
    per(i,n-1,1)suf[i]+=suf[i+1];
    rep(i,1,n){
        ans[i]+=pre[i]+suf[i]+sum[i];
        printf("%lld\n",ans[i]);
    }
    return 0;
}