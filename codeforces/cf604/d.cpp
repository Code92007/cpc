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
const int N=5;
int cnt[N],tmp[N],id[6];
bool used[N];
string cal(int x,int cntx,int y,int cnty){
    if(!cntx && !cnty)return "";
    string ans="";
    char xc=x+'0',yc=y+'0';
    int sg=0;
    if(cntx>cnty)ans+=xc,cntx--,sg^=1;
    else ans+=yc,cnty--;
    rep(i,1,cntx+cnty){
        if(!sg)ans+=xc;
        else ans+=yc;
        sg^=1;
    }
    return ans;
}
bool ok(string x){
    int n=x.size();
    rep(i,0,3)tmp[i]=0;
    int las=-1;
    rep(i,0,n-1){
        int v=x[i]-'0';
        tmp[v]++;
        if(~las && abs(v-las)!=1)return 0;
        if(tmp[v]>cnt[v])return 0;
        las=v;
    }
    rep(i,0,3)if(tmp[i]<cnt[i])return 0;
    puts("YES");
    rep(i,0,n-1){
        printf("%c ",x[i]);
    }
    return 1;
}
bool dfs(int z,vector<string>&x,string y){
    if(z==3)return ok(y);
    rep(i,0,2){
        string w=x[i];
        rep(j,0,1){
            if(j)reverse(w.begin(),w.end());
            if(used[i])continue;
            used[i]=1;
            if(dfs(z+1,x,y+w))return 1;
            used[i]=0;
        }
    }
    return 0;
}
int main(){
    rep(i,0,3)sci(cnt[i]),id[i]=i;
    rep(x,max(0,cnt[3]-1),min(cnt[2],cnt[3]+1)){
        rep(y,max(0,cnt[0]-1),min(cnt[1],cnt[0]+1)){
            int one=cnt[1]-y,two=cnt[2]-x;
            vector<string>z;
            z.pb(cal(0,cnt[0],1,y));
            z.pb(cal(1,one,2,two));
            z.pb(cal(2,x,3,cnt[3]));
            if(dfs(0,z,""))return 0;
        }
    }
    puts("NO");
    return 0;
}