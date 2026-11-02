#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, n;
    std::cin >> x >> n;
    std::multiset<int> stretches = { x };
    std::set<int> lights = { 0, x };
    for (int i = 0; i < n; ++i) {
        int light;
        std::cin >> light;
        auto itr = lights.upper_bound(light);
        int r = *itr;
        int l = *(--itr);
        lights.insert(light);
        stretches.erase(stretches.find(r - l));
        stretches.insert(r - light);
        stretches.insert(light - l);
        std::cout << *stretches.rbegin() << (i == n - 1 ? '\n' : ' ');
    }
}
