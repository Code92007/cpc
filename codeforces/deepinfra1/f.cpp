#include<bits/stdc++.h>
using namespace std;
typedef array<int,2> A;
const int N=2e5+10;
int t,n,a[N],sum[N],stk[N];
bool ok(int p,int w){
    int c=0;
    for(int i=1;i<=n;++i)sum[i]=0;
    for(int i=1;i<=n;++i){
        while(c && a[stk[c]]<a[i])c--;
        if(a[stk[c]]==a[i]){
            sum[stk[c]]++;
            sum[i+1]--;
        }
        stk[++c]=i;
    }
    int now=0;
    for(int i=1;i<=n;++i){
        now+=sum[i];
        if(!now)return 0;
    }
    return 1;
}
void sol(){
    scanf("%d",&n);
    int mx=0,p=1;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
        if(mx==a[i])p=i;
    }
    if(ok(0,0)){
        puts("0");
        return;
    }
    vector<A>ans={{1,mx},{n,mx},{p,1}};
    for(auto &v:ans){
        int pre=a[v[0]];
        a[v[0]]=v[1];
        if(ok(v[0],v[1])){
            puts("1");
            printf("%d %d\n",v[0],v[1]);
            return;
        }
        a[v[0]]=pre;
    }
    puts("2");
    printf("%d %d\n",1,mx);
    printf("%d %d\n",n,mx);
}
int main(){
    scanf("%d",&t);
    while(t--){
        sol();
    }
    return 0;
}
/*
41

*/