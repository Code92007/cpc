#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define pb push_back
#define pte(a) printf("%d\n",a)
#define sci(a) scanf("%d",&(a))

const int N=1e6+10;
int t,n;
char s[N];

void merge(vector<pair<int,int>>& stk) {
    if (stk.empty()) return;
    int sz = stk.size();
    if (sz >= 2 && stk[sz-2].first == stk[sz-1].first) {
        stk[sz-2].second += stk[sz-1].second;
        stk.pop_back();
    }
}

int solve() {
    vector<pair<int,int>> stk;
    
    rep(i,1,n) {
        int x = s[i] - 'A';
        
        if (x == 2) {
            bool deleted = false;
            
            int sz = stk.size();
            if (sz >= 2 && stk[sz-2].first == 0 && stk[sz-1].first == 1) {
                int cntA = stk[sz-2].second;
                int cntB = stk[sz-1].second;
                stk.pop_back();
                stk.pop_back();
                
                if (cntA == cntB) {
                    deleted = true;
                } else if (cntA > cntB) {
                    stk.push_back({0, cntA - cntB});
                    deleted = true;
                } else {
                    stk.push_back({1, cntB - cntA});
                    deleted = true;
                }
            }
            else if (!stk.empty() && stk.back().first == 0) {
                stk.pop_back();
                deleted = true;
            }
            else if (!stk.empty() && stk.back().first == 1) {
                vector<pair<int,int>> bs;
                while (!stk.empty() && stk.back().first == 1) {
                    bs.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(bs.begin(), bs.end());
                
                if (!stk.empty() && stk.back().first == 0) {
                    auto a = stk.back();
                    stk.pop_back();
                    
                    int totalB = 0;
                    for (auto& p : bs) totalB += p.second;
                    
                    if (a.second >= 1) {
                        a.second--;
                        totalB--;
                        deleted = true;
                        
                        if (a.second > 0) stk.push_back(a);
                        for (auto& p : bs) {
                            if (p.second > 0) stk.push_back(p);
                        }
                    } else {
                        stk.push_back(a);
                        for (auto& p : bs) stk.push_back(p);
                    }
                } else {
                    for (auto& p : bs) stk.push_back(p);
                }
            }
            
            if (!deleted) {
                stk.push_back({2, 1});
            }
        } else {
            if (!stk.empty() && stk.back().first == x) {
                stk.back().second++;
            } else {
                stk.push_back({x, 1});
            }
        }
    }
    
    vector<pair<int,int>> final_stk;
    for (auto p : stk) {
        if (p.first == 2) {
            final_stk.push_back(p);
        } else {
            final_stk.push_back(p);
            int sz = final_stk.size();
            while (sz >= 2 && final_stk[sz-2].first == 0 && final_stk[sz-1].first == 1) {
                int cntA = final_stk[sz-2].second;
                int cntB = final_stk[sz-1].second;
                final_stk.pop_back();
                final_stk.pop_back();
                
                if (cntA == cntB) {
                    break;
                } else if (cntA > cntB) {
                    final_stk.push_back({0, cntA - cntB});
                    break;
                } else {
                    final_stk.push_back({1, cntB - cntA});
                    break;
                }
                sz = final_stk.size();
            }
        }
    }
    
    int ans = 0;
    for (auto p : final_stk) {
        if (p.first != 0) {
            ans += p.second;
        }
    }
    
    return ans;
}

int main() {
    sci(t);
    while(t--) {
        scanf("%s", s+1);
        n = strlen(s+1);
        pte(solve());
    }
    return 0;
}