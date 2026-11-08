#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, d;
    cin >> n >> m >> d;

    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    vector<int> rats, emptyCells;
    vector<int> ratId(n * m, -1);

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (grid[x][y] == 'X') continue;

            int p = x * m + y;
            emptyCells.push_back(p);

            if (grid[x][y] == 'R') {
                ratId[p] = (int)rats.size();
                rats.push_back(p);
            }
        }
    }

    const int S = 1 + 2 * d * (d + 1);
    if ((int)rats.size() > 2 * S) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> dist(n * m, -1);
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    // 返回与 start 的网格最短路距离不超过 d 的所有非墙格。
    auto around = [&](int start) {
        vector<int> q;
        q.reserve(S);
        q.push_back(start);
        dist[start] = 0;

        for (int head = 0; head < (int)q.size(); ++head) {
            int v = q[head];
            if (dist[v] == d) continue;

            int x = v / m, y = v % m;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int u = nx * m + ny;
                if (grid[nx][ny] == 'X' || dist[u] != -1) continue;

                dist[u] = dist[v] + 1;
                q.push_back(u);
            }
        }

        for (int v : q) dist[v] = -1;
        return q;
    };

    auto printAnswer = [&](int a, int b) {
        cout << a / m + 1 << ' ' << a % m + 1 << ' '
             << b / m + 1 << ' ' << b % m + 1 << '\n';
    };

    vector<char> killed(rats.size());
    vector<int> firstCandidates = around(rats[0]);

    for (int first : firstCandidates) {
        fill(killed.begin(), killed.end(), false);

        for (int cell : around(first)) {
            if (ratId[cell] != -1) killed[ratId[cell]] = true;
        }

        int firstAlive = -1;
        int aliveCount = 0;
        for (int i = 0; i < (int)rats.size(); ++i) {
            if (!killed[i]) {
                if (firstAlive == -1) firstAlive = i;
                ++aliveCount;
            }
        }

        // 第一枚已经消灭全部老鼠，第二枚放在任意其他空格。
        if (firstAlive == -1) {
            for (int second : emptyCells) {
                if (second != first) {
                    printAnswer(first, second);
                    return 0;
                }
            }
        }

        vector<int> secondCandidates = around(rats[firstAlive]);
        for (int second : secondCandidates) {
            if (second == first) continue;

            int left = aliveCount;
            for (int cell : around(second)) {
                int id = ratId[cell];
                if (id != -1 && !killed[id]) --left;
            }

            if (left == 0) {
                printAnswer(first, second);
                return 0;
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}