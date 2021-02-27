#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        int a, b;
        std::cin >> a >> b;
        if (a > b) {
            std::swap(a, b);
        }
        if (b > a * 2 || (a - b + a) % 3 != 0) {
            std::cout << "NO" << '\n';
        } else {
            std::cout << "YES" << '\n';
        }
    }
    return 0;
}
