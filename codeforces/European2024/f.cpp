#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=2e5+10,M=1e6+10;
int n,m,k,v,id[N];
int dfn[M],now[N];
vector<int>a[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        id[i]=i;
        scanf("%d",&k);
        for(int j=1;j<=k;++j){
            scanf("%d",&v);
            a[i].push_back(v);
        }
        now[i]=(int)a[i].size();
    }
    sort(id+1,id+n+1,[&](int x,int y){
        return now[x]<now[y];
    });
    for(int i=1;i<=n;++i){
        int p=id[i];
        for(auto &v:a[p]){
            if(dfn[v]){
                now[dfn[v]]--;
            }
        }
        for(auto &v:a[p]){
            if(dfn[v] && now[dfn[v]]){
                puts("YES");
                printf("%d %d\n",dfn[v],p);
                return 0;
            }
        }
        for(auto &v:a[p]){
            dfn[v]=p;
        }
    }
    puts("NO");
    return 0;
}