#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;
    int res = 0;
    for (long long L = 1; L * L <= 2 * n; ++L) {
        res += (2 * n) % L == 0 && (2 * n / L - L + 1) % 2 == 0;
    }
    std::cout << (res * 2) << '\n';
}
