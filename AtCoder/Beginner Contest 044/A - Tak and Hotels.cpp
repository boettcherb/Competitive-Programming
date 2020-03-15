#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k, x, y;
    std::cin >> n >> k >> x >> y;
    if (n > k) {
        std::cout << (k * x + (n - k) * y) << '\n';
    } else {
        std::cout << (n * x) << '\n';
    }
    return 0;
}
