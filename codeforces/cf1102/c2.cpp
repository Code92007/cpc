#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];

        vector<ll> ans(n, 0);

        for (int p = 0; p < n; p++) {
            vector<ll> w(n, 0);
            
            // 向右构造
            ll cur = 0;
            for (int i = p + 1; i < p + n; i++) {
                int idx = i % n;
                int prev = (i - 1) % n;
                if (i == p + 1) {
                    cur = h[prev];
                } else {
                    if (cur > h[prev]) {
                        // 保持 cur 不变
                    } else {
                        cur = h[prev];
                    }
                }
                w[idx] = cur;
            }

            // 向左构造
            cur = 0;
            for (int i = p - 1; i > p - n; i--) {
                int idx = (i + n) % n;
                int nxt = (i + 1 + n) % n;
                if (i == p - 1) {
                    cur = h[idx];
                } else {
                    if (cur > h[idx]) {
                        // 保持 cur 不变
                    } else {
                        cur = h[idx];
                    }
                }
                w[idx] = min(w[idx], cur);
            }

            ll sum = 0;
            for (int i = 0; i < n; i++) {
                if (i != p) sum += w[i];
            }
            ans[p] = sum;
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}