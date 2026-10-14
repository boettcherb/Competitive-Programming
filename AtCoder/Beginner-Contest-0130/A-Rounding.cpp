#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, a;
    std::cin >> x >> a;
    std::cout << (x < a ? 0 : 10) << '\n';
}
