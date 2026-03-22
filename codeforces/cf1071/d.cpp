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
const int M=(1<<16)+5;
int t,n;
bool used[M];
vector<int>ans;
int main(){
    sci(t);
    while(t--){
        sci(n);
        int up=(1<<n)-1;
        rep(i,0,up)used[i]=0;
        ans.clear();
        ans.pb(up);
        int now=up;
        used[up]=1;
        while(true){
            int nex=now;
            per(i,n-1,0){
                if(now>>i&1){
                    nex=now^(1<<i);
                    break;
                }
            }
            //printf("now:%d nex:%d\n",now,nex);
            rep(i,0,up){
                if(used[i])continue;
                if((nex&i)!=nex)continue;
                ans.pb(i);
                used[i]=1;
            }
            if(nex==0 && now==0)break;
            now=nex;
        }
        for(auto &v:ans){
            printf("%d ",v);
        }
        puts("");
    }
    return 0;
}