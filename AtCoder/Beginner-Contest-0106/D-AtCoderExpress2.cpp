#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        dp[l][r] += 1;
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        std::cout << dp[l][r] << '\n';
    }
}
