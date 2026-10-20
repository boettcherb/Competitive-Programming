#include <iostream>
#include <vector>

const int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, K;
    std::cin >> n >> K;
    std::vector<int> arr(n), dp(n, INF);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int k = K; k > 0; --k) {
            if (i - k < 0) continue;
            dp[i] = std::min(dp[i], dp[i - k] + std::abs(arr[i] - arr[i - k]));
        }
    }
    std::cout << dp[n - 1] << '\n';
}
