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
int t,n,a[N];
ll cnt1,cnt2;
vector<int>pos[N];
// void add(int i,int j){
//     if(i==j)cnt3++;
//     else cnt1++;
// }
int main(){
    sci(t);
    while(t--){
        sci(n);
        rep(i,1,n)pos[i].clear();
        rep(i,1,n){
            sci(a[i]);
            if(a[i]>n)continue;
            pos[a[i]].pb(i);
        }
        int v=sqrt(n)+1;
        cnt1=cnt2=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=v;++j){
                if(i<=v){
                    if(SZ(pos[i])<SZ(pos[j])){
                        for(auto &p:pos[i]){
                            int w=i*j;
                            if(p+w<=n && a[p+w]==j)cnt1++;
                            if(p-w>=1 && a[p-w]==j)cnt1++;
                        }
                    }
                    else{
                        for(auto &p:pos[j]){
                            int w=i*j;
                            if(p+w<=n && a[p+w]==i)cnt1++;
                            if(p-w>=1 && a[p-w]==i)cnt1++;
                        }
                    }
                }
                else{
                    if(i*j>=n)break;
                    for(auto &p:pos[i]){
                        int w=i*j;
                        if(p+w<=n && a[p+w]==j)cnt2++;
                        if(p-w>=1 && a[p-w]==j)cnt2++;
                    }
                }
            }
        }
        printf("%lld\n",cnt1/2+cnt2);
    }
    return 0;
}
//ai*aj+i=j
//ai/aj+i/aj=j/aj