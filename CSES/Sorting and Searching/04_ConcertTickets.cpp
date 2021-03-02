#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, a;
    std::cin >> n >> m;
    std::multiset<int> prices;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        prices.emplace(a);
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> a;
        auto itr = prices.upper_bound(a);
        if (itr == prices.begin()) {
            std::cout << -1 << '\n';
        } else {
            std::cout << *(--itr) << '\n';
            prices.erase(itr);
        }
    }
    return 0;
}
