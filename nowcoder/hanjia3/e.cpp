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
using namespace std;
const int N=2e5+10;
int t,n,m,k;
ll lb,ub;
vector<A>res;
bool used[N];
bool sol(){
    ll lb=1ll*n*(n-1)/2;
    if(k<lb)return 0;
    vector<int>ans;
    int mx=k-(n-1)*(n-2)/2;
    //printf("mx:%d\n",mx);
    int ban=mx-(n-1);
    int del=0,val=1;
    rep(i,1,n-2){
        int ver=i+1,all=1ll*ver*(ver-1)/2-i;
        ans.pb(val++);
        //printf("i:%d all:%d\n",i,all);
        if(i==n-2)break;
        while(del<all){
            int left=n-2-i;
            int mx2=val+left;
            //printf("i:%d del:%d all:%d mx:%d mx2:%d left:%d val:%d\n",i,del,all,mx,mx2,left,val);
            if(mx-left>mx2){
                mx-=left;
                val++;
                del++;
            }
            else{
                break;
            }
        }
    }
    //puts("gg2");
    ans.pb(mx);
    if(mx>m)return 0;
    //printf("mx:%d\n",mx);
    rep(i,1,m)used[i]=0;
    for(auto &v:ans){
        //printf("v:%d\n",v);
        used[v]=1;
    }
    int c=1;
    vector<P>no;
    rep(i,1,m){
        if(used[i]){
            c++;
            res.pb({c-1,c,i});
            for(int j=1;j<c-1;++j){
                if(SZ(no)>m)break;
                no.pb(P(j,c));
            }
        }
        else{
            if(no.empty())return 0;
            P x=no.back();no.pop_back();
            res.pb({x.fi,x.se,i});
        }
    }
    return 1;
    //1 2 ... n-3 n-2 mx
}
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m),sci(k);
        if(!sol()){
            puts("NO");
        }
        else{
            puts("YES");
            for(auto &x:res){
                printf("%d %d %d\n",x[0],x[1],x[2]);
            }
            res.clear();
        }
    }
    return 0;
}