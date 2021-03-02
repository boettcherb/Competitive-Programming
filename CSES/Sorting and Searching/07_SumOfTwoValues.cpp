#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::cin >> n >> x;
    std::pair<int, int> vals[N];
    for (int i = 0; i < n; ++i) {
        std::cin >> vals[i].first;
        vals[i].second = i + 1;
    }
    std::sort(vals, vals + n);
    int p1 = 0, p2 = n - 1;
    while (p1 < p2) {
        if (vals[p1].first + vals[p2].first < x) {
            ++p1;
        } else if (vals[p1].first + vals[p2].first > x) {
            --p2;
        } else {
            std::cout << vals[p1].second << ' ' << vals[p2].second << '\n';
            break;
        }
    }
    if (p1 >= p2) {
        std::cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}
