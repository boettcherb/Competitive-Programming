#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc = 1;
    std::cin >> tc;
    while (tc--) {
        int n, a, b;
        std::cin >> n >> a >> b;
        if (a + b > n || (a != 0 && b == 0) || (a == 0 && b != 0)) {
            std::cout << "NO" << '\n';
            continue;
        }
        std::vector<int> moves1(n), moves2(n);
        for (int i = 0; i < n; ++i) {
            moves1[i] = moves2[i] = i + 1;
        }
        int ties = n - a - b;
        std::rotate(moves2.begin(), moves2.begin() + a, moves2.end() - ties);
        std::cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            std::cout << moves1[i] << (i == n - 1 ? '\n' : ' ');
        }
        for (int i = 0; i < n; ++i) {
            std::cout << moves2[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
}
