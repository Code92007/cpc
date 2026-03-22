#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#define ll long long
#define ull unsigned ll
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef double db;
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef pair<ll,ll> P;
int t,n,m,l,r,x,w,T;
map<int,vector<P> >add,del;
map<int,ll>now;
set<P>cur;
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m);
        add.clear();del.clear();
        rep(i,1,n){
            scanf("%d%d%d%d",&l,&r,&x,&w);
            add[l].pb(P(x,w));
            del[r+1].pb(P(x,w));
        }
        now.clear();
        cur.clear();
        cur.insert(P(0,0));
        auto it=add.begin(),it2=del.begin();
        rep(i,1,m){
            sci(T);
            while(it!=add.end() && (*it).fi<=T){
                //printf("fi:%d\n",(*it).fi);
                auto y=(*it).se;
                for(auto &z:y){
                    int x=z.fi,w=z.se;
                    if(cur.count(P(now[x],-x))){
                        cur.erase(P(now[x],-x));
                    }
                    now[x]+=w;
                    cur.insert(P(now[x],-x));
                }
                it++;
            }
            while(it2!=del.end() && (*it2).fi<=T){
                //printf("fi2:%d\n",(*it2).fi);
                auto y=(*it2).se;
                for(auto &z:y){
                    int x=z.fi,w=z.se;
                    if(cur.count(P(now[x],-x))){
                        cur.erase(P(now[x],-x));
                    }
                    now[x]-=w;
                    cur.insert(P(now[x],-x));
                }
                it2++;
            }
            //printf("T:%d (%d,%d)\n",T,(*cur.rbegin()).fi,(*cur.rbegin()).se);
            printf("%d\n",-(*cur.rbegin()).se);
        }
    }
}