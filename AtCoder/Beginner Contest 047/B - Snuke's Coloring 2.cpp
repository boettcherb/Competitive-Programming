#include <iostream>

const int N = 105;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int width, height, n, grid[N][N] = { 0 };
    std::cin >> width >> height >> n;
    for (int point = 0; point < n; ++point) {
        int x, y, a;
        std::cin >> x >> y >> a;
        int minX, maxX, minY, maxY;
        switch (a) {
            case 1: minX = 0; maxX = x;     minY = 0; maxY = height; break;
            case 2: minX = x; maxX = width; minY = 0; maxY = height; break;
            case 3: minX = 0; maxX = width; minY = 0; maxY = y;      break;
            case 4: minX = 0; maxX = width; minY = y; maxY = height; break;
            default: return -1;
        }
        for (int i = minX; i < maxX; ++i) {
            for (int j = minY; j < maxY; ++j) {
                grid[i][j] = 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (grid[i][j] == 0) {
                ++res;
            }
        }
    }
    std::cout << res << '\n';
    return 0;
}
