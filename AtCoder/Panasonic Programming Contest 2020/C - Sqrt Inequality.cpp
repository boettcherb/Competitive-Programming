#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long a, b, c;
    std::cin >> a >> b >> c;
    long long d = c - a - b;
    if (d > 0 && 4 * a * b < d * d) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
    }
    return 0;
}
