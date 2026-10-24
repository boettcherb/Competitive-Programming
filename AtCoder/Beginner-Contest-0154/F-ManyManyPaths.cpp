#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;
const int N = 2000010;
std::vector<long long> fact(N), fact_inv(N);

long long mpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long nCr(long long n, long long r) {
    return fact[n] * fact_inv[n - r] % MOD * fact_inv[r] % MOD;
}

long long paths(long long x, long long y) {
    return nCr(x + y, x);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    fact_inv[N - 1] = mpow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) {
        fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;
    }
    long long r1, c1, r2, c2, res = 0;
    std::cin >> r1 >> c1 >> r2 >> c2;
    for (int i = r1; i <= r2; ++i) {
        res = (res + paths(i + 1, c2) - paths(i + 1, c1 - 1) + MOD) % MOD;
    }
    std::cout << res << '\n';
}
