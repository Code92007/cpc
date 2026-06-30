#include<iostream>
using namespace std;
const int N=1e5+10,M=26,K=N*M;
int num[K],nex[N][M],fail[K],tot;
void insert(string s){
    int n=s.size();
    int root=0;
    for(int i=0;i<n;++i){
        int id=s[i]-'a';
        if(!nex[root][id]){
            nex[root][id]=++tot;
        }
        root=nex[root][id];
    }
    num[root]++;
}
void ac_automation(){
    int root=0;
    queue<int>q;
    q.push(root);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<26;++i){
            int p=nex[x][i];
            if(p>0){
                fail[p]=x;
                q.push(p);
            }
            else{
                int y=x;
                while(y>0 && !nex[y][i]){
                    y=fail[y];
                }
                if(y==0)nex[x][i]=0;
                else nex[x][i]=nex[fail[y]][i];
            }
        }
    }
}
bool match(string s){
    int n=s.size();
    int root=0;
    for(int i=0;i<n;++i){
        int id=s[i]-'a';
        if(nex[root][id]){
            root=nex[root][id];
        }
        else{
            while(root>0 && !nex[fail[root]][id]){
                root=fail[root];
            }
            if(!nex[root][id])return 0;
            root=nex[root][id];
        }
        if(num[root]>0)return true;
    }
    return false;
}
int main(){
    return 0;
}
