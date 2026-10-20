#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(3));
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        dp[i][0] = a + std::max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = b + std::max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = c + std::max(dp[i - 1][0], dp[i - 1][1]);
    }
    std::cout << std::max({ dp[n][0], dp[n][1], dp[n][2] }) << '\n';
}
