//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
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
using namespace std;
typedef long long ll;
const int N=3e5+10;
int n,m,a[26],b[26],c;
char s[N],ans[N];
void opmn(int *x){
    rep(j,0,25){
        if(x[j]){
            x[j]--;
            ans[c++]=j+'a';
            break;
        }
    }
}
void opmx(int *x){
    per(j,25,0){
        if(x[j]){
            x[j]--;
            ans[c++]=j+'a';
            break;
        }
    }
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    sort(s+1,s+n+1);
    m=(n+1)/2;
    rep(i,1,m){
        a[s[i]-'a']++;
    }
    scanf("%s",s+1);
    n=strlen(s+1);
    sort(s+1,s+n+1,greater<char>());
    m=n/2;
    rep(i,1,m){
        b[s[i]-'a']++;
    }
    rep(i,1,n){
        int mn=0,mx=25;
        rep(j,0,25){
            if(a[j]){
                mn=j;
                break;
            }
        }
        per(j,25,0){
            if(b[j]){
                mx=j;
                break;
            }
        }
        if(mn>=mx){//甲fxyz越小越好 乙abcf越大越好 ffcxbyaz 交替倒着填  
            int l=c;
            rep(j,i,n){
                if(j&1)opmx(a);
                else opmn(b);
            }
            reverse(ans+l,ans+c);
            break;
        }
        else{
            if(i&1)opmn(a);
            else opmx(b);
        }
    }
    ans[c++]='\0';
    printf("%s\n",ans);
    return 0;
}