#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, prev, cur, res = 0;
    std::cin >> n >> prev;
    for (int i = 1; i < n; ++i) {
        std::cin >> cur;
        if (cur < prev)
            res += prev - cur;
        prev = std::max(prev, cur);
    }
    std::cout << res << '\n';
}
