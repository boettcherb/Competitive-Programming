#include <iostream>
#include <vector>

const int INF = 1e9;
const int T = 1010;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
#endif

    int n, m, c;
    std::cin >> n >> m >> c;
    std::vector<int> money(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> money[i];
    }
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }
    std::vector<std::vector<int>> dp(T, std::vector<int>(n, -INF));
    dp[0][0] = 0;
    for (int t = 1; t < T; ++t) {
        for (int i = 0; i < n; ++i) {
            if (dp[t - 1][i] == -INF) continue;
            for (int adj : g[i]) {
                dp[t][adj] = std::max(dp[t][adj], dp[t - 1][i] + money[adj]);
            }
        }
    }
    int res = 0;
    for (int t = 0; t < T; ++t) {
        if (dp[t][0] == -INF) continue;
        res = std::max(res, dp[t][0] - c * t * t);
    }
    std::cout << res << '\n';
}
