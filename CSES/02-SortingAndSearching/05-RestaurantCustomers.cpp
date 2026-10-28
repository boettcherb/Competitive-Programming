#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> times(2 * n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        times[i] = { a, 0 };
        times[i + n] = { b, 1 };
    }
    std::sort(times.begin(), times.end());
    int res = 0, cur = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (times[i].second == 0) {
            ++cur;
            res = std::max(res, cur);
        } else {
            --cur;
        }
    }
    std::cout << res << '\n';
}
