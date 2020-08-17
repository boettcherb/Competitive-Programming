#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, sx, sy;
    std::cin >> n >> m >> sx >> sy;
    std::pair<int, int> start(sx, sy);
    std::pair<int, int> toCorner(1, sy);
    std::cout << sx << ' ' << sy << '\n';
    std::cout << "1 " << sy << '\n';
    std::pair<int, int> cur(1, 1);
    bool right = true;
    while (cur.first <= n) {
        if (cur != start && cur != toCorner) {
            std::cout << cur.first << ' ' << cur.second << '\n';
        }
        if (right) {
            ++cur.second;
            if (cur.second > m) {
                cur.second = m;
                ++cur.first;
                right = false;
            }
        } else {
            --cur.second;
            if (cur.second == 0) {
                cur.second = 1;
                ++cur.first;
                right = true;
            }
        }
    }
    return 0;
}
