#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
    return x * (x + 1) / 2;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<ll> S(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + nums[i - 1];
    }
    
    // dp[i][j] 用滚动数组
    const ll INF = 1LL << 60;
    vector<ll> dp_prev(n + 1, INF), dp_cur(n + 1, INF);
    dp_prev[0] = 0;
    
    for (int j = 1; j <= k; j++) {
        dp_cur.assign(n + 1, INF);
        deque<int> dq;
        // 初始点 t = j-1，因为前 j 段至少 j 个元素
        for (int i = j; i <= n; i++) {
            // 将 i-1 加入候选
            int t = i - 1;
            if (dp_prev[t] < INF) {
                ll At = dp_prev[t] + (S[t]*S[t] - S[t]) / 2;
                // 维护凸包：队列尾部 pop 直到凸性
                while (dq.size() >= 2) {
                    int t1 = dq[dq.size() - 2], t2 = dq.back();
                    // 检查 (t1, t2, t) 的凸性
                    // (At2 - At1)/(S[t2]-S[t1]) >= (At - At2)/(S[t]-S[t2])
                    ll dy1 = (dp_prev[t2] + (S[t2]*S[t2] - S[t2])/2) - 
                             (dp_prev[t1] + (S[t1]*S[t1] - S[t1])/2);
                    ll dx1 = S[t2] - S[t1];
                    ll dy2 = At - (dp_prev[t2] + (S[t2]*S[t2] - S[t2])/2);
                    ll dx2 = S[t] - S[t2];
                    // 比较 dy1/dx1 >= dy2/dx2
                    if (dy1 * dx2 >= dy2 * dx1) {
                        dq.pop_back();
                    } else {
                        break;
                    }
                }
                dq.push_back(t);
            }
            // 查询最优 t
            while (dq.size() >= 2) {
                int t1 = dq[0], t2 = dq[1];
                ll val1 = dp_prev[t1] + f(S[i] - S[t1]);
                ll val2 = dp_prev[t2] + f(S[i] - S[t2]);
                if (val1 >= val2) {
                    dq.pop_front();
                } else {
                    break;
                }
            }
            if (!dq.empty()) {
                int best_t = dq.front();
                dp_cur[i] = dp_prev[best_t] + f(S[i] - S[best_t]);
            }
        }
        dp_prev = dp_cur;
    }
    
    cout << dp_prev[n] << endl;
    
    return 0;
}