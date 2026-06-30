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
int n,w,mn[2],pos[2],cnt;
array<int,3>tmp;
vector<int>ans;
struct node{
    int a,b,c,d,id,e;
    void read(int i){
        sci(a),sci(b),sci(c);
        if(a-b-c<c)id=-i;
        else id=i;
        d=min(a-b-c,c)+b;
        e=a-d;
    }
    void show(){
        printf("a:%d b:%d c:%d d:%d e:%d id:%d\n",a,b,c,d,e,id);
    }
}e[N],f[N][2];
bool cmp(node a,node b){
    return a.a<b.a;
}
void upd(int i){
    if(e[i].d<=mn[0]){
        mn[1]=mn[0],pos[1]=pos[0];
        mn[0]=e[i].d,pos[0]=i;
    }
    else if(e[i].d<=mn[1]){
        mn[1]=e[i].d,pos[1]=i;
    }
}
void upd3(int i){
    node tmp=e[i];
    rep(j,0,1){
        f[i][j]=f[i-1][j];
    }
    rep(j,0,1){
        if(e[i].e>=f[i][j].e){
            swap(tmp,f[i][j]);
        }
    }
}
void upd2(int l,int x,int r,int res){
    if(res>cnt){
        cnt=res;
        tmp={l,x,r};
    }
    //printf("now:%d tmp:(%d,%d,%d)\n",cnt,tmp[0],tmp[1],tmp[2]);
}
void sol(){
    sci(n),sci(w);
    rep(i,1,n){
        e[i].read(i);
    }
    sort(e+1,e+n+1,cmp);
    ll now=0;
    rep(i,0,1){
        f[0][i].e=0;
    }
    rep(i,1,n){
        now+=e[i].a;
        //e[i].show();
        upd3(i);
    }
    mn[0]=mn[1]=1e9;
    pos[0]=pos[1]=n;
    ll sum=now;
    if(now<=w){
        pte(n);
        rep(i,1,n){
            printf("%d%c",i," \n"[i==n]);
        }
        return;
    }
    per(i,n,1){
        if(i>=2){
            if(now-f[i-1][0].e-f[i-1][1].e<=w){
                upd2(f[i-1][0].id,i,f[i-1][1].id,i);
            }
        }
        if(e[i].b<=w){
            //printf("i:%d eib:%d\n",i,e[i].b);
            upd2(e[i].id,0,0,1);
        }
        now-=e[i].a;
        upd(i);
        //printf("i:%d mn0:%lld mn1:%lld\n",i,mn[0],mn[1]);
        if(now+mn[0]+mn[1]<=w){
            upd2(e[pos[0]].id,i-1,e[pos[1]].id,i+1);
        }
        if(i-1>=1){
            if(now-f[i-1][0].e+mn[0]<=w){
                upd2(e[pos[0]].id,i-1,f[i-1][0].id,i);
            }
        }
    }
    pte(cnt);
    //printf("cnt:%d\n",cnt);
    if(!cnt)return;
    if(tmp[0])ans.pb(-tmp[0]);
    //printf("tmp1:%d e1id:%d\n",tmp[1],e[1].id);
    rep(i,1,tmp[1]){
        if(e[i].id==tmp[0] || e[i].id==tmp[2])continue;
        ans.pb(e[i].id);
    }
    if(tmp[2])ans.pb(tmp[2]);
    for(auto &v:ans){
        printf("%d ",v);
    }
}
int main(){
    sol();
    return 0;
}