//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
void fast(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void sol(){
    int m,n;
    cin>>n;
    m=2*n;
    vector<int>a(m+5);
    vector<int>ans(m+5);
    vector<vector<int>>pos(n,vector<int>());
    for(int i=1;i<=m;++i){
        cin>>a[i];
        a[i]--;
        pos[a[i]].push_back(i);
    }
    vector<vector<array<int,2>> >e(m+5);
    vector<int>color(m+5,-1);
    int id=0;
    for(int j=1;j<=m;j++){
        ++id;
        e[j].push_back({j-1,id});
        e[j-1].push_back({j,id});
        //cout<<"j: "<<a[j]<<" "<<a[j+1]<<endl;
    }
    for(int i=0;i<n;i++){
        int x=pos[i][0],y=pos[i][1];
        ++id;
        e[x-1].push_back({y-1,id});
        e[y-1].push_back({x-1,id});
    }
    vector<bool>vis(3*m+5);
    function<void(int)> dfs = [&](int u){
        //cout<<"u:"<<u<<endl;
        while(!e[u].empty()){
            auto [v,id]=e[u].back();
            e[u].pop_back();
            if(vis[id])continue;
            vis[id]=1;
            if (color[u]!=-1 && color[v]==-1){
                color[v]=color[u]^1;
            }
            dfs(v);
        }
    };
    color[0]=0;
    dfs(0);
    vector<int>res,res2;
    for(int i=1;i<=m;++i){
        //printf("%d ",ans[i]);
        int d=color[i]^color[i-1];
        if(d==1){
            if(i-1)res.push_back(i-1);
        }
    }
    //puts("");
    cout<<(int)res.size()<<endl;
    for(auto &v:res){
        cout<<v<<" ";
    }
    cout<<endl;
}
int main(){
    fast();
    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}
/*
1-2
2-3
3-1
*/