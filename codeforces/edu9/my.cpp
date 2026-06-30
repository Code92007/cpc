#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,k,mn,mx,now;
char s[N];
vector<int>tmp;
vector<vector<int> >q;
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    while(true){
        tmp.clear();
        for(int i=1;i<=n;++i){
            if(s[i]=='R' && s[i+1]=='L'){
                tmp.push_back(i);
                swap(s[i],s[i+1]);
                i+=1;
                mx++;
            }
        }
        if(tmp.empty())break;
        q.push_back(tmp);
    }
    mn=q.size();
    if(!(mn<=k && k<=mx)){
        puts("-1");
    }
    else{
        for(int i=0;i<mn;++i){
            while(!q[i].empty() && k>mn-i){
                k--;
                printf("%d %d\n",1,q[i].back());
                q[i].pop_back();
            }
            if(!q[i].empty()){
                k--;
                printf("%d",q[i].size());
                for(auto x:q[i]){
                    printf(" %d",x);
                }
                puts("");
            }
        }
    }
	return 0;
}