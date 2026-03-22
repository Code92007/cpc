#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<cassert>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
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
const int N=5e6+10,M=1e7+10;
namespace fastIO
{
    static char buf[100000],*h=buf,*d=buf;//缓存开大可减少读入时间，看题目给的空间
    #define gc getchar()
    template<typename T>
    inline void read(T&x)
    {
        int f = 1;x = 0;
        register char c(gc);
        while(c>'9'||c<'0'){
            if(c == '-') f = -1;
            c=gc;
        }
        while(c<='9'&&c>='0')x=(x<<1)+(x<<3)+(c^48),c=gc;
        x *= f;
    }
    template<typename T>
    void output(T x)
    {
        if(x<0){putchar('-');x=~(x-1);}
        static int s[20],top=0;
        while(x){s[++top]=x%10;x/=10;}
        if(!top)s[++top]=0;
        while(top)putchar(s[top--]+'0');
    }
}
using namespace fastIO;
int n,m,sum,v,s[M];
P ok[M];
int main(){
    read(n),read(m);
    assert(n==5000000);
    assert(m==5000000);
    //sci(n),sci(m);
    rep(i,1,n){
        read(s[i]);
        assert(s[i]==1 || s[i]==2);
    }
    int l=1,r=n,fir=0,sec=0;
    rep(j,1,n){//TT
        sum+=s[j];
        if(!fir && s[j]==1)fir=j;
        if(s[j]==1)sec=j;
    }
    ok[sum]=P(l,r);
    while(l<=r){
        if(s[l]==s[r]){
            if(s[l]==2){
                sum-=2;
                if(!sec)l++;
                else if(fir<n-sec+1)l++;
                else r--;
            }
            else{
                sum--,l++;
            }
        }
        else{
            if(s[l]==2){
                ok[sum-1]=P(l,r-1);
                sum-=2;
                l++;
            }
            else{
                ok[sum-1]=P(l+1,r);
                sum-=2;
                r--;
            }
        }
        if(sum)ok[sum]=P(l,r);
    }
    while(m--){
        read(v);
        if(ok[v]==P(0,0))printf("-1 -1\n");
        else printf("%d %d\n",ok[v].fi,ok[v].se);
    }
    return 0;
}