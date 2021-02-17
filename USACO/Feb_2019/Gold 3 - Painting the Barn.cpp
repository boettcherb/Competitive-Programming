#include <iostream>

const int N = 202;

int kadane(int arr[N]) {
    int localMax = 0, globalMax = -2e9;
    for (int i = 0; i < N; ++i) {
        localMax = std::max(arr[i], arr[i] + localMax);
        globalMax = std::max(localMax, globalMax);
    }
    return globalMax;
}

int solve(const int barn[N][N]) {
    std::pair<int, int> best[N] = { {0, 0} };
    for (int i = 0; i < N; ++i) {
        int arr[N] = { 0 };
        for (int j = i; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                arr[k] += barn[j][k];
            }
            int bestRect = kadane(arr);
            for (int k = 0; k < i; ++k) {
                best[k].second = std::max(best[k].second, bestRect);
            }
            for (int k = j; k < N; ++k) {
                best[k].first = std::max(best[k].first, bestRect);
            }
        }
    }
    int bestPair = 0;
    for (int i = 0; i < N; ++i) {
        bestPair = std::max(bestPair, best[i].first + best[i].second);
    }
    return bestPair;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k, barn[N][N] = { 0 }, barn2[N][N] = { 0 };
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; ++x) {
            ++barn[x][y1];
            --barn[x][y2];
        }
    }
    int res = 0, shouldPaint = 0;
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            barn[i][j + 1] += barn[i][j];
            if (barn[i][j] == k) {
                barn[i][j] = -1;
                ++res;
            }
            else if (barn[i][j] == k - 1) {
                barn[i][j] = 1;
                ++shouldPaint;
            }
            else {
                barn[i][j] = 0;
            }
            barn2[j][i] = barn[i][j];
        }
    }
    res += shouldPaint <= 2 ? shouldPaint : std::max(solve(barn), solve(barn2));
    std::cout << res << '\n';
    return 0;
}
