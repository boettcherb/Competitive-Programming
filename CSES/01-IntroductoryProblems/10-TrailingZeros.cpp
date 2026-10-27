#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, mult = 5, res = 0;
    std::cin >> n;
    while (mult <= n) {
        res += n / mult;
        mult *= 5;
    }
    std::cout << res << '\n';
}
