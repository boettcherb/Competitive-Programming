#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::pair<int, int> tasks[N];
    for (int i = 0; i < n; ++i) {
        std::cin >> tasks[i].first >> tasks[i].second;
    }
    std::sort(tasks, tasks + n);
    long long curTime = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        curTime += tasks[i].first;
        res += tasks[i].second - curTime;
    }
    std::cout << res << '\n';
    return 0;
}
