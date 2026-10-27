#include <iostream>

const long long MOD = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, res = 1;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        res = res * 2 % MOD;
    }
    std::cout << res << '\n';
}
