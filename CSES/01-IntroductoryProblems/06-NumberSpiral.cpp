#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        long long y, x, res;
        std::cin >> y >> x;
        if (y >= x)
            res = (y * y - y + 1) + (y - x) * (y % 2 == 0 ? 1 : -1);
        else
            res = (x * x - x + 1) + (x - y) * (x % 2 == 0 ? -1 : 1);
        std::cout << res << '\n';
    }
}
