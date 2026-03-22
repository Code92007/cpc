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
int t,n,k,now[N],nex[N],cnt;
vector<int>a[N];
map<int,int>b[N],all;
ll ans,sum1,sum2,sum3;
ll sum4,sum5,sum6;
int mex(int i){
    for(auto &v:a[i]){
        b[i][v]++;
    }
    int sz=SZ(a[i]);
    rep(v,0,sz){
        if(!b[i].count(v))return v;
    }
    return sz;
}
void init(){
    rep(i,1,n){
        a[i].clear();
        b[i].clear();
    }
    all.clear();
    cnt=0;
    sum1=sum2=sum3=0;
}
void check(){
    ll sum4=0,sum5=0,sum6=0;
    rep(i,1,n){
        rep(j,1,n){
            if(i==j)continue;
            for(auto &v:a[i]){
                int nv;
                if(now[i]<v)nv=now[i];
                else{
                    if(b[i][v]==1)nv=v;
                    else nv=now[i];
                }
                sum5+=nv;
                int ano=(v==now[j]?nex[j]:now[j]);
                sum6+=ano;
                //printf("i:%d j:%d v:%d nv:%d ano:%d\n",i,j,v,nv,ano);
                rep(k,1,n){
                    if(k==i || k==j)continue;
                    sum4+=now[k];
                }
            }
        }
    }
    printf("sum4:%lld sum5:%lld sum6:%lld\n",sum4,sum5,sum6);
}
int main(){
    sci(t);
    while(t--){
        sci(n);
        init();
        ans=0;
        rep(i,1,n){
            sci(k);
            int v;
            rep(j,1,k){
                sci(v);
                cnt++;
                all[v]++;
                a[i].pb(v);
            }
            now[i]=mex(i);
            for(int j=now[i]+1;;j++){
                if(!b[i].count(j)){
                    nex[i]=j;
                    break;
                }
            }
            //printf("i:%d now:%d nex:%d\n",i,now[i],nex[i]);
            for(auto &v:a[i]){
                int nv;
                if(now[i]<v)nv=now[i];
                else{
                    if(b[i][v]==1)nv=v;
                    else nv=now[i];
                }
                ans+=1ll*(n-1)*nv;
                sum2+=1ll*(n-1)*nv;
            }
        }
        rep(i,1,n){
            int num=cnt-SZ(a[i]);
            ans+=1ll*num*(n-2)*now[i];
            sum1+=1ll*num*(n-2)*now[i];
            ans+=1ll*num*now[i];
            ans+=1ll*(all[now[i]]-b[i][now[i]])*(nex[i]-now[i]);//insert mex(b)
            sum3+=1ll*num*now[i];
            sum3+=1ll*(all[now[i]]-b[i][now[i]])*(nex[i]-now[i]);
        }
        //check();
        //printf("sum1:%lld sum2:%lld sum3:%lld\n",sum1,sum2,sum3);
        printf("%lld\n",ans);
    }
    return 0;
}