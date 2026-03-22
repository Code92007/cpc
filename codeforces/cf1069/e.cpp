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
int t,n,k,a[N],cnt[N],las[N],id[N];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(k);
        rep(i,1,n)cnt[i]=0,las[i]=-1;
        rep(i,1,n){
            sci(a[i]);
            cnt[a[i]]++;
            id[i]=i;
            las[i]=i;
        }
        sort(id+1,id+n+1,[&](int x,int y){
            if(cnt[x]!=cnt[y])return cnt[x]<cnt[y];
            return las[x]<las[y];
        });
        if(cnt[id[n]]==1){
            rep(i,0,k-1){
                printf("%d%c",a[i%n+1]," \n"[i==k-1]);
            }
        }
        else{
            if(id[2]==a[n])swap(id[2],id[3]);//特判
            n=3;
            rep(i,0,k-1){
                int p=i%n+1;
                printf("%d%c",id[p]," \n"[i==k-1]);
            }
        }
        // printf("id:");
        // rep(i,1,n){
        //     printf("%d ",id[i]);
        // }
        // puts("");
    }
    return 0;
}
//1 3 2 1 2 3