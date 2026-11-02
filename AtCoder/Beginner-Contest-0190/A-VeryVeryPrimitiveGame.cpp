#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std::cin >> a >> b >> c;
    if ((c == 0 && a > b) || (c == 1 && a >= b))
        std::cout << "Takahashi" << '\n';
    else
        std::cout << "Aoki" << '\n';
}
