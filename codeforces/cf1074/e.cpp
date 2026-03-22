#include<bits/stdc++.h>
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
int t,n,m,k,a[N],b[N],lb[N],rb[N],cnt[N];
char s[N];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m),sci(k);
        rep(i,1,n)sci(a[i]);
        rep(i,1,m)sci(b[i]);
        sort(b+1,b+m+1);
        sci(k);
        scanf("%s",s+1);
        int now=0,mn=0,mx=0;
        rep(i,1,k){
            if(s[i]=='L')now--;
            else now++;
            mn=min(mn,now);
            mx=max(mx,now);
            lb[i]=mn,rb[i]=mx;
        }
        rep(i,1,n){
            int l=1,r=k;
            while(l<=r){
                int mid=(l+r)/2;
                int L=a[i]+lb[mid],R=a[i]+rb[mid];
                int x=lower_bound(b+1,b+m+1,L)-b;
                int y=upper_bound(b+1,b+m+1,R)-b;
                if(x==y)l=mid+1;
                else r=mid-1;
            }
            cnt[l]++;
        }
        int die=0;
        rep(i,1,k){
            die+=cnt[i];
            printf("%d%c",n-die," \n"[i==k]);
        }
        rep(i,1,k+1)cnt[i]=0;
    }
    return 0;
}