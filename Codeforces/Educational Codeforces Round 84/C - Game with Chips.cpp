#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 0; i < 2 * k; ++i) {
        int a, b;
        std::cin >> a >> b;
    }
    std::cout << (n + m + n * m - 3) << '\n';
    for (int i = 0; i < n - 1; ++i) {
        std::cout << 'D';
    }
    for (int i = 0; i < m - 1; ++i) {
        std::cout << 'L';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            std::cout << (i % 2 == 0 ? 'R' : 'L');
        }
        if (i < n - 1) {
            std::cout << 'U';
        }
    }
    std::cout << '\n';
    return 0;
}
