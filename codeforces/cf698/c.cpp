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
const int N=5e3+10;
int n,id[N];
P a[N];
P operator-(P a,P b){
    return P(a.fi-b.fi,a.se-b.se);
}
ll dot(P a,P b){
    //printf("a.fi:%lld b.fi:%lld a.se:%lld b.se:%lld\n",a.fi,b.fi,a.se,b.se);
    return 1ll*a.fi*b.fi+1ll*a.se*b.se;
}
bool no(int j){
    if(j==1)return 0;
    P nex=a[j+1]-a[j],pre=a[j-1]-a[j];
    return dot(nex,pre)<=0;
}
void op(int j){
    swap(a[j],a[j-1]);
    swap(id[j],id[j-1]);
}
int main(){
    sci(n);
    rep(i,1,n){
        scanf("%lld%lld",&a[i].fi,&a[i].se);
        id[i]=i;
    }
    rep(i,3,n){
        //P las=a[i-2]-a[i-1],now=a[i]-a[i-1];
        //printf("i:%d dot:%lld\n",i,dot(las,now));
        if(no(i-1)){
            op(i-1);
            // P las=a[i-2]-a[i-1],now=a[i]-a[i-1];
            // printf("i:%d dot:%lld\n",i,dot(las,now));
            per(j,i-2,2){
                if(no(j)){
                    op(j);
                    if(no(j+1)){
                        op(j+1);
                    }
                }
                else{
                    break;
                }
                // P nex=a[j+1]-a[j],pre=a[j-1]-a[j];
                // if(dot(nex,pre)<=0){
                //     printf("j:%d swap\n",j);
                //     swap(a[j],a[j-1]);
                //     swap(id[j],id[j-1]);
                //     P nex2=a[j+]
                // }
                // else{
                //     break;
                // }
            }
        }
    }
    rep(i,1,n){
        printf("%d%c",id[i]," \n"[i==n]);
    }
    return 0;
}
/*
注意到1 2 3不合法的时候3 1 2，2 1 3，2 3 1，3 2 1都是合法的
1 2 3 4 5
3 4 5不合法，交换3 4使4 3 5合法，1 2 4 3 5
2 4 3不合法，交换2 4，1 4 2 3 5，可能会导致2 3 5不合法（那再交换一下3 2就一定合法了，因为2 4 3中4是钝角）
*/