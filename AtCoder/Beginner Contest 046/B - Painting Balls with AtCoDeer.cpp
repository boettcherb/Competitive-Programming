#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, k;
    std::cin >> n >> k;
    long long res = k;
    for (int i = 1; i < n; ++i) {
        res *= k - 1;
    }
    std::cout << res << '\n';
    return 0;
}
