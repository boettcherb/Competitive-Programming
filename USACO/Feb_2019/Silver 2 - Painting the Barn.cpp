#include <iostream>

const int N = 1005;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k, barn[N][N] = { 0 };
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; ++x) {
            ++barn[x][y1];
            --barn[x][y2];
        }
    }
    int res = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            res += barn[i][j] == k;
            barn[i][j + 1] += barn[i][j];
        }
    }
    std::cout << res << '\n';
    return 0;
}
