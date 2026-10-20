#include <iostream>
#include <vector>

using vecLL = std::vector<long long>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, W;
    std::cin >> n >> W;
    std::vector<vecLL> dp(n + 1, vecLL(W + 1));
    for (int i = 1; i <= n; ++i) {
        int weight, value;
        std::cin >> weight >> value;
        for (int w = 1; w <= W; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (w - weight >= 0)
                dp[i][w] = std::max(dp[i][w], dp[i - 1][w - weight] + value);
        }
    }
    std::cout << dp[n][W] << '\n';
}
