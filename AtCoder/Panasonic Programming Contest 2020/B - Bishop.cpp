#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long h, w;
    std::cin >> h >> w;
    if (w == 1 || h == 1) {
        std::cout << 1 << '\n';
    } else if (h % 2 == 1 && w % 2 == 1) {
        std::cout << (h * w / 2 + 1) << '\n';
    } else {
        std::cout << (h * w / 2) << '\n';
    }
    return 0;
}
