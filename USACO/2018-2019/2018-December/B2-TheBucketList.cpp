#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
#endif

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> pts;
    for (int i = 0; i < n; ++i) {
        int s, t, b;
        std::cin >> s >> t >> b;
        pts.emplace_back(s, b);
        pts.emplace_back(t, -b);
    }
    std::sort(pts.begin(), pts.end());
    int cur_used = 0, max_used = 0;
    for (int i = 0; i < 2 * n; ++i) {
        cur_used += pts[i].second;
        max_used = std::max(cur_used, max_used);
    }
    std::cout << max_used << '\n';
}
