#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 1005;
int N,K;
long long v = 0;
pair<int,long long> noita[MAXN];
int trans(string s){
    if(s[0]=='P'&&s[1]=='a'){
        return 0;
    }
    if(s[0]=='M'&&s[1]=='o'){
        return 1;
    }
    if(s[0]=='M'&&s[1]=='u'){
        return 4;
    }
    if(s[0]=='J'){
        return 5;
    }
    if(s[s.length()-1]=='*'){
        return 3;
    }
    return 2;
}
void showNoita(pair<int,int> p){
    printf("%d %d\n",p.first,p.second);
}
int pos;
int pasC;
int pas[MAXN*2];
pair<int,long long> jec[MAXN*2];
int jecC;
int re;
int setoff[MAXN*2];
int setC;
void go(){
    // printf("go re %d pos %d v %d \n",re,pos,v);
    jecC = 0;
    setC=0;
    if(re == 1){
        pos = 1;
        re = 0;
    }
    re = 0;
    if(pos>N){
        pos = 1;
        re = 1;
    }
    long long u = 1;
    while(u!=0){
        if(pos>N){
            if(re==0){
                re = 1;
            }else{
                return;
            }
            pos = 1;
            continue;
        }
        // printf("pos %d v %d u %d\n",pos,v,u);
        if(noita[pos].first==1){
            setoff[++setC]=pos;
            v+=noita[pos].second;
            pos++;
            continue;
        }
        if(noita[pos].first==0){
            pos++;
            continue;
        }
        if(noita[pos].first==2||noita[pos].first==3){
            setoff[++setC]=pos;
            jec[++jecC].first = pos;
            jec[jecC].second = v+noita[pos].second;
            if(noita[pos].first==3){
                pos++;
                continue;
            }
            pos++;
            u--;
            continue;
        }
        if(noita[pos].first==4){
            setoff[++setC]=pos;
            u+=noita[pos].second;
            u--;
            pos++;
            continue;
        }
        if(noita[pos].first==5){
            setoff[++setC]=pos;
            if(v==0){
                u--;
                pos++;
                continue;
            }else{
                int nxt;
                if(re==0){
                    re = 1;
                    // pos = 1;
                    nxt = 1;
                }else{
                    nxt = pos+1;
                }
                
                for(int t = 1;t<=noita[pos].second;++t){
                    while(noita[nxt].first==0&&nxt<=N){
                        nxt++;
                    }
                    nxt++;
                    if(nxt>N){
                        return;
                    }
                }
                // printf("pos %d nxt %d\n",pos,nxt);
                if(nxt>N){
                    return;
                }
                pos = nxt;
                u--;
                u++;
                continue;
            }
        }
    }



    return;
}
int main(){
    cin>>N>>K;
    pos = 1;
    for(int i = 1;i<=N;++i){
        string s;
        cin>>s;
        noita[i].first = trans(s);
        cin>>noita[i].second;
        if(noita[i].first==0){
            pasC++;
            pas[pasC]=i;
        }
    }
    // for(int i = 1;i<=N;++i){
    //     showNoita(noita[i]);
    // }
    for(int i = 1;i<=K;++i){

        go();
        for(int i = 1;i<=pasC;++i){
            printf("%d ",pas[i]);
            // cout<<
        }
        for(int i = 1;i<=setC;++i){
            printf("%d ",setoff[i]);
        }
        for(int i = 1;i<=jecC;++i){
            printf("(%d,%lld) ",jec[i].first,jec[i].second);
        }
        printf("\n");
    }



    return 0;
}