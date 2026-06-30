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
char s[N],x[5],y[5];
bool ban[26][26];
int t,n,m,k,dp[N],las[26],nex[N][26];
int main(){
    sci(t);
    while(t--){
        sci(n),sci(m),sci(k);
        rep(i,0,25){
            rep(j,0,25){
                ban[i][j]=0;
            }
        }
        scanf("%s",s+1);
        rep(i,1,m){
            scanf("%s%s",x,y);
            ban[x[0]-'a'][y[0]-'a']=1;
        }
        rep(i,0,25)las[i]=n+1;
        per(i,n,1){
            dp[i]=1;
            int v=0;
            rep(j,0,25){
                nex[i][j]=n+1;
                if(las[j]>n)continue;
                if(ban[s[i]-'a'][j])continue;
                v=max(v,dp[las[j]]);
                nex[i][j]=las[j];
                //printf("i:%d j:%d las:%d\n",i,j,las[j]);
            }
            las[s[i]-'a']=i;
            dp[i]+=v;
            //printf("i:%d dp:%d\n",i,dp[i]);
        }
        bool ok=0;
        vector<int>ans;
        int now=-1;
        rep(i,0,25){
            if(las[i]>n)continue;
            if(dp[las[i]]>=k){
                ok=1;
                now=las[i];
                break;
            }
        }
        if(!ok){
            puts("-1");
            continue;
        }
        ans.pb(now);
        //printf("now:%d\n",now);
        while(SZ(ans)<k){
            //printf("now:%d\n",now);
            rep(i,0,25){
                if(ban[s[now]-'a'][i])continue;
                int p=nex[now][i];
                //printf("now:%d i:%d p:%d\n",now,i,p);
                if(p>n)continue;
                //printf("i:%d p:%d dp:%d\n",i,p,dp[p]);
                if(SZ(ans)+dp[p]<k)continue;
                ans.pb(p);
                now=p;
                break;
            }
        }
        for(auto &v:ans){
            putchar(s[v]);
        }
        puts("");
    }
    return 0;
}