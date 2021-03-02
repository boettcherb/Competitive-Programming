#include <iostream>
#include <algorithm>

const int N = 4e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::pair<int, bool> times[N];
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        times[i * 2] = std::make_pair(a, true);
        times[i * 2 + 1] = std::make_pair(b, false);
    }
    std::sort(times, times + 2 * n);
    int cur = 0, res = 0;
    for (int i = 0; i < 2 * n; ++i) {
        cur += times[i].second ? 1 : -1;
        res = std::max(res, cur);
    }
    std::cout << res << '\n';
    return 0;
}
