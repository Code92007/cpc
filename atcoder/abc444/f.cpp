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
typedef pair<int,int> P;
typedef array<int,3> A;
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
const int N=1e5+10,M=4e6+10;
int t,n,a[N],b[M],c,id[N];
P son[M];
ll m,now[M],sum;
map<int,bool>mp;
void dfs(int x){
    if(mp.count(x))return;
    mp[x]=true;
    b[c++]=x;
    if(x>=2){
        int w=x/2;
        dfs(w);
        if(w!=x-w)dfs(x-w);
    }
}
/*
1. 不要考虑去限制m次操作次数是否超限，而操作次数限制了总根数，大于等于mid的根数合法时，一定可以正好取到(n+m+1)/2根，
此时若总根数不合法，一定是小于mid的根数不合法，所以考虑限制小于mid的根数，让<mid的棍子根数小于等于(n+m-1)/2根，>=mid的棍子根数等于(n+m+1)/2
【约束A】：<mid的棍子根数小于等于(n+m-1)/2根
【约束B】：最小化>=mid的(n+m+1)/2的长度s，
【约束C】：剩下的长度是sum-s，sum-s>=(n+m-1)/2，每根最短长度是1
2. 
(1）>=2*mid的长度，能折半就折半，因为两半都够长
(2）=2*mid-1的，可以折也可以不折，放到最后讨论，要在满足【约束A】的情况下，让【约束B】尽可能小
(3）[mid,2*mid-1)的，一定是不折，但统计答案
(4) <mid的，一定是不折，也不统计答案
*/
bool ok(int mid){
    rep(i,0,c-1)now[i]=0;
    ll smallcnt=0,bigsum=0,smalllim=(n+m-1)/2;
    rep(i,1,n){
        int p=id[i];
        if(b[p]<mid)smallcnt++;
        else now[p]++;
    }
    //printf("mid:%d smallcnt:%lld smalllim:%lld\n",mid,smallcnt,smalllim);
    if(smallcnt>smalllim)return 0;
    ll all=0;
    per(i,c-1,0){
        //if(b[i]<2*mid-1)break;
        int ls=son[i].fi,rs=son[i].se;
        if(~ls && b[ls]>=mid){//>=2*mid
            now[ls]+=now[i];
            now[rs]+=now[i];
            now[i]=0;
        }
        else if(~rs && b[rs]>=mid){//=2*mid-1
            ll v=min(smalllim-smallcnt,now[i]);
            now[ls]+=v;
            now[rs]+=v;
            now[i]-=v;
        }
        else{//<2*mid-1
            break;
        }
    }
    //统计最短的(n+m+1)/2根的长度
    ll s=0,need=(n+m+1)/2;
    rep(i,0,c-1){
        if(b[i]>=mid){
            ll v=min(need,now[i]);
            s+=1ll*v*b[i];
            need-=v;
        }
    }
    //printf("mid:%d s:%lld sum:%lld\n",mid,s,sum);
    return sum-s>=smalllim && need==0;
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        scanf("%lld",&m);
        mp.clear();
        c=0;
        sum=0;
        rep(i,1,n){
            sci(a[i]);
            sum+=a[i];
            dfs(a[i]);
        }
        sort(b,b+c);
        c=unique(b,b+c)-b;
        rep(i,0,c-1){
            if(b[i]==1){
                son[i]=P(-1,-1);
            }
            else{            
                int sm=b[i]/2,bg=b[i]-sm;
                int ls=lower_bound(b,b+c,sm)-b;
                int rs=lower_bound(b,b+c,bg)-b;
                son[i]=P(ls,rs);
            }
        }
        rep(i,1,n){
            id[i]=lower_bound(b,b+c,a[i])-b;
        }
        int l=1,r=1e9,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(ok(mid))ans=mid,l=mid+1;//不满足的棍子每根长度切为1
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//30 15 15 7 7 8 8 3 3 4 4 4 4 4 4
//