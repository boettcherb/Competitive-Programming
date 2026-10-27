#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        if (a > b) std::swap(a, b);
        std::cout << (2 * a >= b && (2 * a - b) % 3 == 0 ? "YES\n" : "NO\n");
    }
}
