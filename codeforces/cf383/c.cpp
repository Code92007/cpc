#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],to[N],col[N];
queue<int>q;
int main(){
    scanf("%d",&n);
    m=2*n;
    for(int i=1;i<=n;++i){
        scanf("%d%d",&a[i],&b[i]);
        to[a[i]]=b[i];
        to[b[i]]=a[i];
    }
    for(int i=1;i<=m;++i){
        if(col[i])continue;
        q.push(i);
        col[i]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            int adj=(u%2==0?u-1:u+1);
            for(auto v:{to[u],adj}){
                if(col[v])continue;
                col[v]=3-col[u];
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d %d\n",col[a[i]],col[b[i]]);
    }
    return 0;
}