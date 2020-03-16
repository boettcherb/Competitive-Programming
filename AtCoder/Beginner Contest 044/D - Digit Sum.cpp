#include <iostream>

const long long INF = 1e18;

long long f(long long b, long long n) {
    return n < b ? n : f(b, n/b) + n % b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, s;
    std::cin >> n >> s;
    if (n < s) {
        std::cout << -1 << '\n';
    } else if (n == s) {
        std::cout << n + 1 << '\n';
    } else {
        for (long long i = 2; i * i <= n; ++i) {
            if (f(i, n) == s) {
                std::cout << i << '\n';
                return 0;
            }
        }
        long long ans = INF;
        for (long long i = 1; i * i <= n; ++i) {
            long long b = (n - s) / i + 1;
            if (b >= 2 && f(b, n) == s) {
                ans = b < ans ? b : ans;
            }
        }
        std::cout << (ans == INF ? -1 : ans) << '\n';
    }
    return 0;
}
