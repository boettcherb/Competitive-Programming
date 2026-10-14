#include <iostream>
#include <vector>

using vecLL = std::vector<long long>;
const int MOD = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> s(n + 1), t(m + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> t[i];
    }
    std::vector<vecLL> dp(n + 1, vecLL(m + 1, 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i] == t[j])
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
    }
    std::cout << dp[n][m] << '\n';
}
