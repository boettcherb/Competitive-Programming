#include <iostream>
#include <vector>

const long long INF = 1e18;
const int V = 100001;
using vecLL = std::vector<long long>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, W;
    std::cin >> n >> W;
    std::vector<vecLL> dp(n + 1, vecLL(V, INF));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int w, v;
        std::cin >> w >> v;
        for (int j = 1; j < V; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - v < 0 || dp[i - 1][j - v] == INF) continue;
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j - v] + w);
        }
    }
    for (int i = V - 1; i > 0; --i) {
        if (dp[n][i] <= W) {
            std::cout << i << '\n';
            break;
        }
    }
}
