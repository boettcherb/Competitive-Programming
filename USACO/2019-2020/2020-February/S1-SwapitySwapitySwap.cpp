#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> successor;

int getKthSuccessor(int x, int k) {
    for (int bit = 0; k > 0; ++bit) {
        if (k & 1)
            x = successor[bit][x];
        k >>= 1;
    }
    return x;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
#endif

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::pair<int, int>> p(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> p[i].first >> p[i].second;
    }
    std::vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        arr[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        std::reverse(arr.begin() + p[i].first, arr.begin() + p[i].second + 1);
    }
    successor = std::vector<std::vector<int>>(32, std::vector<int>(n + 1));
    successor[0] = arr;
    for (int j = 1; j < 32; ++j) {
        for (int i = 1; i <= n; ++i) {
            successor[j][i] = successor[j - 1][successor[j - 1][i]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << getKthSuccessor(i, k) << '\n';
    }
}
