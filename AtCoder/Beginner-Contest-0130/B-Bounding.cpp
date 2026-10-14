#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, pos = 0, res = 1;
    std::cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int L;
        std::cin >> L;
        pos += L;
        res += pos <= x;
    }
    std::cout << res << '\n';
}
