#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
#endif

    int n;
    std::string road;
    std::cin >> n >> road;
    std::set<std::string> s;
    for (int i = 1; i <= n; ++i) {
        s.clear();
        bool all_diff = true;
        for (int j = 0; j <= n - i; ++j) {
            if (!s.insert(road.substr(j, i)).second) {
                all_diff = false;
                break;
            }
        }
        if (all_diff) {
            std::cout << i << '\n';
            break;
        }
    }
}
