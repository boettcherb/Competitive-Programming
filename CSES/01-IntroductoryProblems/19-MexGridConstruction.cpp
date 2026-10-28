#include <iostream>
#include <vector>

int smallest(int i, int j, std::vector<std::vector<int>>& mex, int n) {
    std::vector<bool> seen(2 * n);
    for (int k = 0; k < i; ++k) {
        seen[mex[k][j]] = true;
    }
    for (int k = 0; k < j; ++k) {
        seen[mex[i][k]] = true;
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (!seen[i]) return i;
    }
    return 2 * n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> mex(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mex[i][j] = smallest(i, j, mex, n);
            std::cout << mex[i][j] << (j == n - 1 ? '\n' : ' ');
        }
    }
}
