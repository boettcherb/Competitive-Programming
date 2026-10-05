#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

const int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
#endif

    int n, m, k;
    std::string str;
    std::cin >> n >> m >> k >> str;
    std::vector<std::vector<int>> dist(m, std::vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> dist[i][j];
        }
    }
    for (int x = 0; x < m; ++x) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][x] + dist[x][j]); 
            }
        }
    }
    std::vector<std::vector<int>> cost(n + 1, std::vector<int>(m));
    for (int i = 1; i <= n; ++i) {
        int cur = str[i - 1] - 'a';
        for (int j = 0; j < m; ++j) {
            cost[i][j] = dist[cur][j] + cost[i - 1][j];
        }
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, INF));
    for (int j = 0; j < m; ++j) {
        dp[k][j] = cost[k][j];
    }
    dp[k][m] = *std::min_element(dp[k].begin(), dp[k].end());
    for (int i = k + 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = dp[i - 1][j] + dist[str[i - 1] - 'a'][j];
            if (i >= 2 * k) {
                int alt = cost[i][j] - cost[i - k][j] + dp[i - k][m];
                dp[i][j] = std::min(dp[i][j], alt);
            }
        }
        dp[i][m] = *std::min_element(dp[i].begin(), dp[i].end());
    }
    std::cout << dp[n][m] << '\n';
}
