#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<double> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];
    }
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(n + 1));
    dp[1][0] = 1.0 - p[1];
    dp[1][1] = p[1];
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] * (1.0 - p[i]);
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] * (1.0 - p[i]) + dp[i - 1][j - 1] * p[i];
        }
    }
    double res = 0.0;
    for (int j = n / 2 + 1; j <= n; ++j) {
        res += dp[n][j];
    }
    std::cout << std::fixed << std::setprecision(10) << res << '\n';
}
