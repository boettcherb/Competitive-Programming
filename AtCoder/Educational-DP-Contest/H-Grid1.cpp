#include <iostream>
#include <vector>   

const int MOD = 1e9 + 7;
using vecLL = std::vector<long long>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> grid(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> grid[i];
        grid[i] = " " + grid[i];
    }
    std::vector<vecLL> dp(n + 1, vecLL(m + 1));
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '#') continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    std::cout << dp[n][m] << '\n';
}
