#include <iostream>

const int N = 55;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, a, arr[N];
    std::cin >> n >> a;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    long long dp[N][N][N * N] = { 0 };
    for (int i = 1; i <= n; ++i) {
        ++dp[i][1][arr[i - 1]];
        for (int k = 0; k < N * N; ++k) {
            dp[i][1][k] += dp[i - 1][1][k];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= i; ++j) {
            for (int k = 0; k < N * N; ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (k >= arr[i - 1]) {
                    dp[i][j][k] += dp[i - 1][j - 1][k - arr[i - 1]];
                }
            }
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res += dp[n][i][a * i];
    }
    std::cout << res << '\n';
    return 0;
}
