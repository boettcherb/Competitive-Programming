#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long w, h, x, y;
    std::cin >> w >> h >> x >> y;
    bool mult = x * 2 == w && y * 2 == h;
    std::cout << (w * h / 2.0) << ' ' << mult << '\n';
}
