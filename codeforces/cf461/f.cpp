//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int N=3e5+10;
int n,k,cnt[N];
bool keep[N];
vector<int>res;
bool sol(){
    ll sum=0;
    for(int i=1;i<=n;++i){
        sum+=cnt[i];
        if(sum>=k){
            vector<int>w;
            for(int j=1;j<=i;++j){
                keep[j]=1;
            }
            for(int j=i/2+1;j<i;++j){
                w.push_back(j);
            }
            sort(w.begin(),w.end(),[&](int x,int y){
                return cnt[x]>cnt[y];
            });
            //printf("sum:%d i:%d\n",sum,i);
            for(auto &v:w){
                if(sum-cnt[v]<k)continue;
                sum-=cnt[v];
                keep[v]=0;
            }
            //printf("sum:%d\n",sum);
            for(int j=1;j<=i;++j){
                if(keep[j])res.push_back(j);
            }
            return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        for(int j=2*i;j<=n;j+=i){
            cnt[j]++;
        }
    }
    if(!sol())puts("No");
    else{
        puts("Yes");
        printf("%d\n",(int)(res.size()));
        for(auto &v:res){
            printf("%d ",v);
        }
    }
    return 0;
}