#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> movies[i].second >> movies[i].first;
    }
    std::sort(movies.begin(), movies.end());
    int res = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (movies[i].second >= cur) {
            ++res;
            cur = movies[i].first;
        }
    }
    std::cout << res << '\n';
}
