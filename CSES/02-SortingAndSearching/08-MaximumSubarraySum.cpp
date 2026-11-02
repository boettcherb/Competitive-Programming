#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    long long sum = 0, res = -1e18;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        sum += x;
        res = std::max(res, sum);
        if (sum < 0) sum = 0;
    }
    std::cout << res << '\n';
}
