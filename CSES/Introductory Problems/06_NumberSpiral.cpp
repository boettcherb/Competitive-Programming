#include <iostream>

long long sumFirstN(long long n) {
    return n < 1 ? 0 : n * (n + 1) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        long long i, j;
        std::cin >> i >> j;
        if (i > j) {
            long long a = i / 2 + 1;
            long long b = 1LL + 4LL * (a - 1) + 8LL * sumFirstN(a - 2);
            std::cout << (i % 2 ? b + j - 1 : b - j) << '\n';
        } else {
            long long a = (j + 1) / 2;
            long long b = 2LL + 8LL * sumFirstN(a - 1);
            std::cout << (j % 2 ? b - i : b + i - 1) << '\n';
        }
    }
    return 0;
}
