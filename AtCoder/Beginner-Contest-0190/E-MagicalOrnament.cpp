#include <iostream>
#include <vector>
#include <queue>

const int INF = 2e9;

std::vector<std::vector<int>> dp;
int dist[20][20];
int k;

int rec(int bitmask, int last) {
    if (bitmask == (1 << k) - 1) return 0;
    if (dp[bitmask][last] != INF) return dp[bitmask][last];
    int res = INF;
    for (int i = 0; i < k; ++i) {
        if (!(bitmask & (1 << i)) && dist[last][i] != INF) {
            res = std::min(res, dist[last][i] + rec(bitmask | (1 << i), i));
        }
    }
    return dp[bitmask][last] = res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::cin >> k;
    std::vector<int> special(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> special[i];
    }
    for (int i = 0; i < k; ++i) {
        std::queue<int> q;
        std::vector<int> specialDist(n + 1, INF);
        q.push(special[i]);
        specialDist[special[i]] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int adj : g[cur]) {
                if (specialDist[adj] > specialDist[cur] + 1) {
                    specialDist[adj] = specialDist[cur] + 1;
                    q.push(adj);
                }
            }
        }
        for (int j = 0; j < k; ++j) {
            dist[i][j] = specialDist[special[j]];
        }
    }
    dp = std::vector<std::vector<int>>(1 << k, std::vector<int>(k, INF));
    int res = INF;
    for (int i = 0; i < k; ++i) {
        res = std::min(res, rec(1 << i, i));
    }
    std::cout << (res == INF ? -1 : res + 1) << '\n';
}
