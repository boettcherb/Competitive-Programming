#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::multiset<int> set;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        auto itr = set.upper_bound(a);
        if (itr != set.end()) {
            set.erase(itr);
        }
        set.emplace(a);
    }
    std::cout << set.size() << '\n';
    return 0;
}
