#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << (a * d - b * c) << '\n';
}
