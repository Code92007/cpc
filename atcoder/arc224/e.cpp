//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
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
using namespace std;
const int N=1e6+10;
int t,n;
char s[N];
vector<int>stk;
int main(){
    sci(t);
    while(t--){
        stk.clear();
        scanf("%s",s+1);
        n=strlen(s+1);
        stk.clear();
        int res=0;
        rep(i,1,n){
            int x=s[i]-'A';
            if(x==0)stk.pb(0);
            else if(x==1){
                while(!stk.empty() && stk.back()!=0)stk.pop_back();//本质是把匹配上的前缀 A AB 也压回栈里了 A是0，AB是1，ABC是2，匹配不上再pop
                if(stk.empty())res++;
                else stk.back()=1;
            }
            else{
                while(!stk.empty() && stk.back()!=1)stk.pop_back();
                if(stk.empty())res++;
                else stk.pop_back();
            }
            //printf("i:%d res:%d\n",i,res);
        }
        pte(res);
    }
    return 0;
}