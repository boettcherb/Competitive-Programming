#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, div = 5, res = 0;
    std::cin >> n;
    while (div <= n) {
        res += n / div;
        div *= 5;
    }
    std::cout << res << '\n';
    return 0;
}
