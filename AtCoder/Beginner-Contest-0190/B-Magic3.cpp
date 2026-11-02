#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s, d;
    std::cin >> n >> s >> d;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        bool canDamage = x < s && y > d;
        if (canDamage) {
            std::cout << "Yes" << '\n';
            return 0;
        }
    }
    std::cout << "No" << '\n';
}
