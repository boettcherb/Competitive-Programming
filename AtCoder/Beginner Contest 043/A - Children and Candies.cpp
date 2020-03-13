#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, res = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        res += i;
    }
    std::cout << res << '\n';
    return 0;
}
