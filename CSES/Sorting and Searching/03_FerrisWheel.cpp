#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::cin >> n >> x;
    std::multiset<int> set;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        set.emplace(a);
    }
    int res = 0;
    while (!set.empty() && *(--set.end()) > x / 2) {
        auto itr = set.upper_bound(x - *(--set.end()));
        if (itr != set.begin()) {
            set.erase(--itr);
        }
        set.erase(--set.end());
        ++res;
    }
    std::cout << (res + (set.size() + 1) / 2) << '\n';
    return 0;
}
