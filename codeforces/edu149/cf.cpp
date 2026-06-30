#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=1e5+10;
int t,n,cnt[26];
char s[N];
vector<int>pre,suf,kind;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        n=strlen(s);
        for(int i=0;i<26;++i)cnt[i]=0;
        kind.clear();
        for(int i=0;i<n;++i){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<26;++i){
            if(cnt[i]){
                kind.push_back(i);
            }
        }
        reverse(kind.begin(),kind.end());
        for(int i=0;i<26;++i){
            if(cnt[i]>0){
                kind.pop_back();
                for(int j=1;j<=cnt[i]/2;++j){
                    pre.push_back(i);
                    suf.push_back(i);
                }
                cnt[i]%=2;
                if(!cnt[i])continue;
                if(kind.size()>=2){
                    pre.push_back(i);
                    while(!kind.empty()){
                        int x=kind.back();
                        kind.pop_back();
                        for(int j=1;j<=cnt[x];++j){
                            suf.push_back(x);
                        }
                    }
                }
                else if(kind.size()==1){
                    int v=kind[0];
                    for(int j=1;j<=cnt[v]/2;++j){
                        pre.push_back(v);
                        suf.push_back(v);
                    }
                    cnt[v]%=2;
                    if(cnt[i])pre.push_back(i);
                    if(cnt[v])suf.push_back(v);
                }
                else{
                    if(cnt[i])pre.push_back(i);
                }
                break;
            }
        }
        reverse(pre.begin(),pre.end());
        for(auto &v:suf)putchar(v+'a');
        for(auto &v:pre)putchar(v+'a');
        puts("");
        pre.clear();
        suf.clear();
    }
    return 0;
}