#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        int x1, y1, z1, x2, y2, z2;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int res = std::min(z1, y2) * 2;
        z1 -= std::min(z1, y2);
        if (z2 > x1 + z1) {
            res -= (z2 - (x1 + z1)) * 2;
        }
        std::cout << res << '\n';
    }
    return 0;
}
