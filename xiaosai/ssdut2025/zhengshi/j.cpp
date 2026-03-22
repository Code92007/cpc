#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<assert.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<int,int> P;
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
const int N=25,K=52,M=2e6+10;
int a[]= {
    21, 13, 0, 0,
    34, 16, 19, 0,
    47, 22, 18, 32,
    60, 30, 20, 28,
    74, 39, 25, 27,
    89, 49, 31, 29,
    106 , 60, 38, 33,
    123 , 72, 47, 39,
    148 , 86, 57, 47,
    166 , 102 , 70, 56,
    189 , 119 , 84, 68,
    216 , 141 , 102 , 83,
    248 , 167 , 125 , 105 ,
};
vector<int>las[K];
int n,m,ans[N],stk[M],c;
char l[5]="DHCP",r[15]="23456789TJQKA",s[5];
int id(char x,char y){
    int w=0;
    rep(i,0,3){
        if(l[i]==x){
            w+=i;
        }
    }
    rep(i,0,12){
        if(r[i]==y){
            w+=i*4;
        }
    }
    return w;
}
bool find(char *x,int y,int z){
    rep(i,0,z-1){
        if(x[i]==y)return 1;
    }
    return 0;
}
void cal(int p,int w,int val){
    int pre=las[val].back(),all=c-pre+1,now=1<<(w%4);
    per(j,c,pre){
        int card=stk[j],col=card%4,val2=card/4;
        las[val2].pop_back();
        now|=1<<col;
    }
    c=pre-1;
    int kind=__builtin_popcount(now);
    //printf("all:%d now:%d kind:%d\n",all,now,kind);
    all--;kind--;
    int hash=all*4+kind;
    ans[p]+=a[hash];
    printf("%d %d\n",p+1,a[hash]);
}
int main(){
    sci(n),sci(m);
    //assert(1<=n && n<=24);
    //assert(1<=m && m<=2000000);
    rep(i,0,m-1){
        scanf("%s",s);
        //assert(find(l,s[0],4));
        //assert(find(r,s[1],13));
        int w=id(s[0],s[1]),val=w/4;
        //printf("i:%d w:%d\n",i,w);
        if(!las[val].empty()){
            cal(i%n,w,val);
        }
        else{
            stk[++c]=w;
            las[val].pb(c);
        }
    }
    rep(i,0,n-1){
        printf("%d%c",ans[i]," \n"[i==n-1]);
    }
    return 0;
}