#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::multiset<int> tops;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        auto itr = tops.upper_bound(x);
        if (itr != tops.end())
            tops.erase(itr);
        tops.insert(x);
    }
    std::cout << tops.size() << '\n';
}
