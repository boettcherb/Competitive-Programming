#include <iostream>

const int MOD = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        res = (res * 2) % MOD;
    }
    std::cout << res << '\n';
    return 0;
}
