#include <iostream>
#include <vector>

const int K = 2e6 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
#endif

    int n, q;
    std::cin >> n >> q;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::vector<std::vector<long long>> dp(n, std::vector<long long>(n));
    int freq[K] = { 0 };
    int seen[K] = { 0 };
    for (int i = 0; i < n - 2; ++i) {
        int curTime = i + 1;
        seen[arr[i + 1] + K / 2] = curTime;
        freq[arr[i + 1] + K / 2] = 1;
        for (int j = i + 2; j < n; ++j) {
            int target = -(arr[i] + arr[j]) + K / 2;
            if (target >= 0 && target < K && seen[target] == curTime) {
                dp[i][j] += freq[target];
            }
            int val = arr[j] + K / 2;
            if (seen[val] != curTime) {
                seen[val] = curTime;
                freq[val] = 0;
            }
            ++freq[val];
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = n - 2; i >= 0; --i) {
            dp[i][j] += dp[i + 1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] += dp[i][j - 1];
        }
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        --l; --r;
        std::cout << dp[l][r] << '\n';
    }
}
