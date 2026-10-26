#include <iostream>
#include <vector>
#include <iomanip>

const int N = 101;
using vecD = std::vector<double>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<std::vector<vecD>> dp(N, std::vector<vecD>(N, vecD(N)));
    for (int i = 99; i >= a; --i) {
        for (int j = 99; j >= b; --j) {
            for (int k = 99; k >= c; --k) {
                double coins = i + j + k;
                dp[i][j][k] = 1.0;
                dp[i][j][k] += i / coins * dp[i + 1][j][k];
                dp[i][j][k] += j / coins * dp[i][j + 1][k];
                dp[i][j][k] += k / coins * dp[i][j][k + 1];
            }
        }
    }
    std::cout << std::fixed << std::setprecision(9) << dp[a][b][c] << '\n';
}
