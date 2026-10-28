#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::multiset<int> tickets;
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        tickets.insert(t);
    }
    for (int i = 0; i < m; ++i) {
        int c;
        std::cin >> c;
        auto itr = tickets.upper_bound(c);
        if (itr == tickets.begin()) {
            std::cout << -1 << '\n';
        } else {
            std::cout << *(--itr) << '\n';
            tickets.erase(itr);
        }
    }
}
