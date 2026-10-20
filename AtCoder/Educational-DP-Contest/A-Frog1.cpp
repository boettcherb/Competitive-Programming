#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> arr(n), dp(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    dp[1] = std::abs(arr[0] - arr[1]);
    for (int i = 2; i < n; ++i) {
        int j1 = std::abs(arr[i] - arr[i - 1]);
        int j2 = std::abs(arr[i] - arr[i - 2]);
        dp[i] = std::min(dp[i - 1] + j1, dp[i - 2] + j2);
    }
    std::cout << dp[n - 1] << '\n';
}
