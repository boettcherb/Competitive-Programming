#include <iostream>
#include <vector>

const long long MOD = 998244353;

long long mpow(long long a, long long b) {
    a = (a % MOD + MOD) % MOD;
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, p;
    std::cin >> n >> p;
    std::vector<long long> dp(n + 1);
    dp[1] = 1;
    long long p2 = p * mpow(100, MOD - 2) % MOD; // p/100%M -> p*100^(M-2)%M
    long long p1 = (1 - p2 + MOD) % MOD;   // (1-p/100)%M
    for (int i = 2; i <= n; ++i) {
        dp[i] = (1 + p2 * dp[i - 2] + p1 * dp[i - 1]) % MOD;
    }
    std::cout << dp[n] << '\n';
}
