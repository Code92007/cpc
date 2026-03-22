//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
void fast(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void sol(){
    int m;
    cin>>m;
    vector<int>a(m),c(m);
    vector<int>ans(m),res;
    for(int i=0;i<m;++i){
        cin>>a[i];
        a[i]--;
    }
    for(int i=0;i<m;++i){
        cin>>c[i];
        c[i]--;
    }
    vector<int>deg(m);
    for(int i=0;i<m;++i){
        deg[a[i]]++;
        deg[c[i]]++;
    }
    for(auto &v:deg){
        if(v&1){
            cout<<"-1"<<endl;
            return;
        }
    }
    vector<vector<array<int,2>> >e(m);
    for(int i=0;i<m;++i){
        e[a[i]].push_back({c[i],i});
        e[c[i]].push_back({a[i],i});
    }
    vector<bool>vis(m);
    function<void(int)> dfs = [&](int u){
        while(!e[u].empty()){
            auto [v,id]=e[u].back();
            e[u].pop_back();
            if(vis[id])continue;
            vis[id]=1;
            if(a[id]==v)ans[id]=1;
            dfs(v);
        }
    };
    for(int i=0;i<m;++i){
        dfs(i);
    }
    for(int i=0;i<m;++i){
        if(ans[i]==1)res.push_back(i+1);
    }
    cout<<(int)res.size()<<endl;
    for(auto &v:res){
        cout<<v<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    fast();
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}