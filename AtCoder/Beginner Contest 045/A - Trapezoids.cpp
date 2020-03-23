#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    double a, b, h;
    std::cin >> a >> b >> h;
    std::cout << (int) ((a + b) / 2 * h) << '\n';
    return 0;
}
