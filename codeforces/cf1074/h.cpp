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
const int N=2e5+10;
int t,n,k,res[N];
ll a[N],sum[N],mx;
//p被换到x之后[l,r]的和
ll op(int l,int r){
    return sum[r]-(l-1<0?0:sum[l-1]);
}
ll cal(int l,int r,int p,int x){
    if(l>r)return 0;
    bool pre=(l<=p && p<=r);
    bool now=(l<=x && x<=r);
    ll val;
    if(pre==now){
        if(pre)val=op(l,r);
        else{
            if(p<l){
                if(x<l)val=op(l,r);
                else val=op(l+1,r+1);
            }
            else{
                if(x<l)val=op(l-1,r-1);
                else val=op(l,r);
            }
        }
    }
    else{
        if(!pre){
            if(p<l)val=op(l+1,r)+a[p];
            else val=op(l,r-1)+a[p];
        }
        else{
            if(x<l)val=op(l-1,r)-a[p];
            else val=op(l,r+1)-a[p];
        }
    }
    //printf("l:%d r:%d p:%d x:%d val:%lld\n",l,r,p,x,val);
    return val;
}
bool ok(int i,int p,int c){
    int now=p,next=p;
    ll cur=cal(1,p-1,i,p),my=a[i];
    //printf("i:%d p:%d c:%d cur:%lld\n",i,p,c,cur);
    int against=0;
    while(now<=n){
        if(my>(mx>>c))return 1;
        //printf("my:%lld cur:%lld against:%d\n",my,cur,against);
        if(cur<my || (cur==my && against)){
            my+=cur;
            now=next;
        }   
        else if(c){
            c--;
            my+=cur;
            now=next;
        }
        else{
            return 0;
        }
        against++;
        if(my>mx)return 1;
        if(now==n)break;
        int l=now+1,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(cal(now+1,mid,i,p)>my)r=mid-1;
            else l=mid+1;
        }
        //printf("i:%d p:%d c:%d now:%d next:%d cal:%lld\n",i,p,c,now,r,cal(now+1,r,i,p));
        if(r==now){
            if(!c)return 0;
            else r=now+1;
        }
        cur=cal(now+1,r,i,p);
        //printf("cur:%lld\n",cal(now+1,r,i,p));
        next=r;
    }
    return 1;
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        mx=0;
        rep(i,1,n){
            scanf("%lld",&a[i]);
            mx=max(mx,a[i]);
            sum[i]=sum[i-1]+a[i];
            res[i]=0;
        }
        k=min(k,32);
        if(k==0){
            rep(i,1,n){
                int l=1,r=n;
                while(l<=r){
                    int mid=(l+r)/2;
                    //printf("(1,%d,%d,%d):%d\n",mid,i,n,cal(1,mid,i,n));
                    if(cal(1,mid,i,n)<a[i])l=mid+1;
                    else r=mid-1;
                }
                //printf("i:%d r:%d\n",i,r);
                if(ok(i,r+1,0))res[i]=r+1;
                else res[i]=0;
            }
        }
        else{
            rep(i,1,n){
                int l=1,r=n;
                while(l<=r){
                    int mid=(l+r)/2;
                    //printf("(1,%d,%d,%d):%d\n",mid,i,n,cal(1,mid,i,n));
                    if(cal(1,mid,i,n)<a[i])l=mid+1;
                    else r=mid-1;
                }
                //printf("i:%d r:%d\n",i,r);
                int rb=0;
                if(ok(i,r+1,k))rb=r+1;
                l=min(n,rb+1),r=n;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(ok(i,mid,k))r=mid-1;
                    else l=mid+1;
                }
                //printf("[%d,%d] [%d,%d]\n",1,rb,r+1,n);
                if(rb>=r)res[i]=n;
                else res[i]=n-r+rb;
            }
        }
        rep(i,1,n){
            printf("%d%c",res[i]," \n"[i==n]);
        }
    }
    return 0;
}