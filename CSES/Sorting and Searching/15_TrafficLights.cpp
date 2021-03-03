#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int x, n;
    std::cin >> x >> n;
    std::set<std::pair<int, int>> ranges = { {0, x} };
    std::multiset<int> sizes = { x };
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        auto itr = --ranges.upper_bound({a, 0});
        int pos = (*itr).first, size = (*itr).second;
        ranges.erase(itr);
        ranges.emplace(pos, a - pos);
        ranges.emplace(a, size + pos - a);
        sizes.erase(sizes.find(size));
        sizes.emplace(a - pos);
        sizes.emplace(size + pos - a);
        std::cout << *(--sizes.end()) << ' ';
    }
    std::cout << '\n';
    return 0;
}
