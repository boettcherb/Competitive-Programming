#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
#endif

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i].first >> p[i].second;
    }
    int maxArea = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int xVals[3] = { p[i].first, p[j].first, p[k].first };
                int yVals[3] = { p[i].second, p[j].second, p[k].second };
                std::sort(xVals, xVals + 3);
                std::sort(yVals, yVals + 3);
                if (xVals[0] != xVals[1] && xVals[1] != xVals[2]) continue;
                if (yVals[0] != yVals[1] && yVals[1] != yVals[2]) continue;
                int curArea = (xVals[2] - xVals[0]) * (yVals[2] - yVals[0]);
                maxArea = std::max(maxArea, curArea);
            }
        }
    }
    std::cout << maxArea << '\n';
}
