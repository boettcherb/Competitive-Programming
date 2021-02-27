#include <iostream>

const int N = 1e4 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    long long dp[N] = { 0, 0, 6, 28, 96 };
    int numFull = 0;
    for (int i = 5; i <= n; ++i) {
        long long prevSquares = (i - 1) * (i - 1);
        dp[i] = dp[i - 1];
        dp[i] += 5 * (prevSquares - 2);
        dp[i] += 4 * (prevSquares - 3);
        dp[i] += 2 * numFull * (prevSquares - 4);
        long long newSquares = 2 * i - 1;
        dp[i] += newSquares * (newSquares - 1) / 2 - 2;
        ++numFull;
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << dp[i] << '\n';
    }
    return 0;
}
