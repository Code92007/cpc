//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
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
const int N=1e6+10,mod=998244353;
typedef long long ll;
struct SAM{
    struct NODE{
        int ch[26];
        int len,fa,sz,pos;
        NODE(){memset(ch,0,sizeof(ch));len=fa=sz=pos=0;}
    }dian[N<<1];
    int las=1,tot=1,len,m;
    char s[N],t[N];
    int p,l[N],r[N],dp[N],pre[N];
    vector<int>e[N];
    int nex[N];
    void kmppre(){
        int i=0,j=nex[0]=-1;
        while(i<m){
            while(j!=-1&&t[i]!=t[j])j=nex[j];
            nex[++i]=++j;
        }
    }
    void kmp(){
        int i,j;
        kmppre();
        i=j=0;
        pre[0]=-1;
        while(i<len){
            while(j!=-1&&s[i]!=t[j])j=nex[j];
            i++;j++;
            pre[i]=pre[i-1];
            if(j==m){
                pre[i]=i;
                j=nex[j];
            }
            //printf("i:%d j:%d pre:%d\n",i,j,pre[i]);
        }
    }
    void add(int c,int pos){
        int p=las;
        int np=las=++tot;
        dian[np].pos=pos;
        dian[np].sz=1;
        dian[np].len=dian[p].len+1;
        for(;p&&!dian[p].ch[c];p=dian[p].fa)dian[p].ch[c]=np;
        if(!p)dian[np].fa=1;
        else{
            int q=dian[p].ch[c];
            if(dian[q].len==dian[p].len+1)dian[np].fa=q;
            else{
                int nq=++tot;dian[nq]=dian[q];
                dian[nq].sz=0;
                dian[nq].len=dian[p].len+1;
                dian[q].fa=dian[np].fa=nq;
                for(;p&&dian[p].ch[c]==q;p=dian[p].fa)dian[p].ch[c]=nq;
            }
        }
    }
    void dfs(int u){
        int no=1;
        for(auto &v:e[u]){
            dfs(v);
            no=1ll*no*dp[v]%mod;
        }
        int yes=max(0,r[u]-l[u]+1);
        dp[u]=(no+yes)%mod;
        //printf("u:%d p:%d l:%d r:%d yes:%d no:%d dp:%d\n",u,p,l[u],r[u],yes,no,dp[u]);
    }
    void init(){
        scanf("%s%s",s,t);
        len=strlen(s);
        m=strlen(t);
        reverse(s,s+len);
        reverse(t,t+m);
        for(int i=0;i<len;i++){
            add(s[i]-'a',i);
        }
        kmp();
        for(int i=1;i<=tot;++i){
            e[dian[i].fa].push_back(i);
            l[i]=dian[dian[i].fa].len+1;
            r[i]=dian[i].len;
            int p=dian[i].pos;
            if(~pre[p+1]){
                int L=pre[p+1]-1-m+1;
                r[i]=min(r[i],p-(L+1)+1);//p-pre[p]+m-1
            }
            //printf("i:%d l:%d r:%d\n",i,l[i],r[i]);
        }
        dfs(1);
        int ans=(dp[1]-1+mod)%mod;
        printf("%d\n",ans);
    }
}sam;
int main(){
    sam.init();
    return 0;
}