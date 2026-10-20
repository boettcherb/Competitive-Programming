#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;
    int n = (int) a.length(), m = (int) b.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    std::string res;
    int x = n, y = m;
    while (x > 0 && y > 0) {
        if (dp[x][y] == dp[x - 1][y]) {
            --x;
        } else if (dp[x][y] == dp[x][y - 1]) {
            --y;
        } else {
            --x;
            --y;
            res += a[x];
        }
    }
    std::reverse(res.begin(), res.end());
    std::cout << res << '\n';
}
