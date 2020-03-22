#include <iostream>

const int N = 2010;

bool inRange(int val, int l, int r) {
    return l <= val && val <= r;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, h, l, r, arr[N];
    std::cin >> n >> h >> l >> r;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int dp[N][N] = { 0 };
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += arr[i - 1];
        for (int j = 0; j <= i; ++j) {
            bool good = inRange((sum - j) % h, l, r);
            dp[i][j] = dp[i - 1][j] + good;
            if (j > 0) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + good);
            }
        }
    }
    int res = 0;
    for (int j = 0; j <= n; ++j) {
        res = std::max(res, dp[n][j]);
    }
    std::cout << res << '\n';
    return 0;
}
