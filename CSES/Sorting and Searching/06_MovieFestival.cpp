#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::pair<int, int> times[N];
    for (int i = 0; i < n; ++i) {
        std::cin >> times[i].second >> times[i].first;
    }
    std::sort(times, times + n);
    int curTime = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (times[i].second >= curTime) {
            curTime = times[i].first;
            ++res;
        }
    }
    std::cout << res << '\n';
    return 0;
}
