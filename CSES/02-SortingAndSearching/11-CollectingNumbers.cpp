#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, res = 1;
    std::cin >> n;
    std::vector<bool> seen(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> x;
        res += seen[x + 1];
        seen[x] = true;
    }
    std::cout << res << '\n';
}
