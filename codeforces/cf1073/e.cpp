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
int t,n;
int ask(int i,int j){
    printf("? %d %d\n",i,j);
    fflush(stdout);
    int v;
    sci(v);
    return v;
}
void sol(){
    int las=-1,mid=n,l=-1;
    per(i,n-1,1){
        int v=ask(i,i+1);
        if(v==1 && las==0){
            l=i;
            break;
        }
        else if(v==0 && las==1){
            mid=i;
        }
        las=v;
    }
    if(l==-1){
        printf("! -1\n");
        fflush(stdout);
        return;
    }
    vector<int>L,R,all;
    rep(i,l+1,mid)L.pb(i);//单减，逆序单增
    rep(i,mid+1,n)R.pb(i);//单增
    // printf("L:");
    // for(auto &v:L)printf("%d ",v);puts("");
    // printf("R:");
    // for(auto &v:R)printf("%d ",v);puts("");
    reverse(R.begin(),R.end());//单减，逆序单增
    while(SZ(all)<n-l){
        if(!SZ(L)){
            int w=R.back();
            R.pop_back();
            all.pb(w);
        }
        else if(!SZ(R)){
            int w=L.back();
            L.pop_back();
            all.pb(w); 
        }
        else{
            int x=L.back(),y=R.back(),v=ask(x,y);
            if(v==1)L.pop_back(),all.pb(x);
            else R.pop_back(),all.pb(y);
        }
    }
    vector<int>ans;
    bool has=0;
    for(auto &v:all){
        if(!has){
            int x=ask(v,l);
            if(x==1)ans.pb(v);
            else{
                has=1;
                //printf("v:%d l:%d\n",v,l);
                ans.insert(ans.begin(),v);
                ans.pb(l);
            }
        }
        else{
            ans.pb(v);
        }
    }
    printf("!");
    rep(i,1,l-1)printf(" %d",i);
    for(auto &v:ans)printf(" %d",v);
    printf("\n");
    fflush(stdout);
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        sol();
    }
    return 0;
}