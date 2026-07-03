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
typedef pair<ll,int> P;
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
const ll INF=1e18;
int n,m,cnt[N],p[N],b[N];
ll ans[N],L[N],R[N];
struct node{
    int id,pos,len;
}e[N];
map<ll,int>q;//增序动态维护不交若干青蛙区间
set<P>mosq;
int main(){
    sci(n),sci(m);
    rep(i,1,n){
        sci(e[i].pos);
        sci(e[i].len);
        e[i].id=i;
        ans[i]=e[i].len;
    }
    sort(e+1,e+n+1,[&](node a,node b){
        return a.pos<b.pos;
    });
    ll now=-1;
    q[-1]=q[INF]=0;
    L[0]=R[0]=INF;
    rep(i,1,n){
        ll l=e[i].pos,r=e[i].pos+e[i].len;
        if(now<r){
            l=max(l,now+1);
            q[l]=e[i].id;
            L[e[i].id]=l;
            R[e[i].id]=r;
        }
        now=max(now,r);
    }
    //mosq.insert(P(INF,0));
    rep(i,1,m){
        sci(p[i]),sci(b[i]);
        auto it=q.upper_bound(p[i]);
        it--;
        int id=(*it).se;
        //printf("it:(%d,%d)\n",(*it).fi,id);
        if(L[id]<=p[i] && R[id]>=p[i]){
            R[id]+=b[i];
            cnt[id]++;
            ans[id]+=b[i];
            while(!mosq.empty()){
                auto p=mosq.lower_bound(P(L[id],0));
                if(p==mosq.end())break;
                P x=*p;
                //tot1++;
                //if(tot1==100)break;
                if(x.fi<=R[id]){
                    R[id]+=b[x.se];
                    cnt[id]++;
                    ans[id]+=b[x.se];
                    mosq.erase(x);
                    if(mosq.empty())break;
                }
                else{
                    break;
                }
            }
            it++;
            while(it!=q.end()){
                //puts("gg2");
                int id2=(*it).se;
                if(R[id]>=R[id2]){
                    //puts("gg3");
                    q.erase(it++);
                }
                else{
                    //puts("gg4");
                    if(R[id]>=L[id2]){
                        //puts("gg5");
                        q.erase(it);
                        L[id2]=R[id]+1;
                        q[L[id2]]=id2;
                    }
                    break;
                }
            }
            //puts("gg6");
        }
        else{
            //puts("ins");
            mosq.insert(P(p[i],i));   
        }
    }
    rep(i,1,n){
        printf("%d %lld\n",cnt[i],ans[i]);
    }
    return 0;
}