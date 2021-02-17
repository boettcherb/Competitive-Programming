#include <iostream>

const int N = 25;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n, places[N][N];
    std::cin >> k >> n;
    for (int session = 0; session < k; ++session) {
        for (int place = 0; place < n; ++place) {
            int cow;
            std::cin >> cow;
            places[cow - 1][session] = place;
        }
    }
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int less = 0;
            for (int session = 0; session < k; ++session) {
                less += places[i][session] < places[j][session];
            }
            res += less == k || less == 0;
        }
    }
    std::cout << res << '\n';
    return 0;
}