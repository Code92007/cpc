#include <bits/stdc++.h>
using namespace std;

struct State {
    int y;
    int val;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int m = 1 << n;

        vector<vector<State>> row(m);

        for (int i = 0; i < m; i++) {
            int p;
            cin >> p;
            row[i].push_back({p, 1});
        }

        for (int k = 0; k < n; k++) {
            int cnt = (int)row.size() / 2;
            vector<vector<State>> nxt(cnt);

            for (int x = 0; x < cnt; x++) {
                auto &L = row[2 * x];
                auto &R = row[2 * x + 1];

                int i = 0, j = 0;

                while (i < (int)L.size() || j < (int)R.size()) {
                    int py = INT_MAX;

                    if (i < (int)L.size()) py = min(py, L[i].y >> 1);
                    if (j < (int)R.size()) py = min(py, R[j].y >> 1);

                    int q00 = 0, q01 = 0, q10 = 0, q11 = 0;

                    while (i < (int)L.size() && (L[i].y >> 1) == py) {
                        if (L[i].y & 1) q01 = L[i].val;
                        else q00 = L[i].val;
                        i++;
                    }

                    while (j < (int)R.size() && (R[j].y >> 1) == py) {
                        if (R[j].y & 1) q11 = R[j].val;
                        else q10 = R[j].val;
                        j++;
                    }

                    int best = max(q00 + q11, q01 + q10);

                    if (best > 0) {
                        nxt[x].push_back({py, best});
                    }
                }
            }

            row.swap(nxt);
        }

        cout << row[0][0].val << '\n';
    }

    return 0;
}
