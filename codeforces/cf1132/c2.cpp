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
const int N=2e5+10;
int t,a,b;
vector<int>tmp,ans;
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
void dfs(int x,int l){
    if(x==b){
        if(ans.empty() || SZ(ans)>SZ(tmp)){
            ans=tmp;
        }
        return;
    }
    if(SZ(ans)>0 && SZ(tmp)==SZ(ans))return;
    for(int i=b;i>=l;--i){
        int d=i-x;
        if(gcd(x,d)>1)continue;
        if(SZ(ans)>0 && SZ(tmp)==SZ(ans))return;
        tmp.pb(d);
        dfs(i,i+1);
        tmp.pop_back();
    }
}
int main(){
    sci(t);
    while(t--){
        sci(a),sci(b);
        if(a==b){
            puts("0");
        }
        else{
            int w=b-a,g=gcd(a,w);
            if(g==1){
                puts("1");
                pte(w);
            }
            else if(gcd(w-1,a)==1){
                //assert(gcd(a,w-1)==1);
                puts("2");
                printf("%d %d\n",w-1,1);
            }
            else{
                tmp.clear();
                ans.clear();
                dfs(a,max(a+1,b-100));
                pte(SZ(ans));
                for(auto &v:ans){
                    printf("%d ",v);
                }
                puts("");
            }
        }
    }
    return 0;
}