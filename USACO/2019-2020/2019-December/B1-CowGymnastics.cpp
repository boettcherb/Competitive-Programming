#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
#endif

    int k, n;
    std::cin >> k >> n;
    // rankings[c][i] = ranking of cow c in session i
    std::vector<std::vector<int>> rankings(n + 1, std::vector<int>(k));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int cow;
            std::cin >> cow;
            rankings[cow][i] = j;
        }
    }
    int res = 0;
    for (int c1 = 1; c1 < n; ++c1) {
        for (int c2 = c1 + 1; c2 <= n; ++c2) {
            bool all_before = true, all_after = true;
            for (int i = 0; i < k; ++i) {
                all_before &= (rankings[c1][i] < rankings[c2][i]);
                all_after &= (rankings[c1][i] > rankings[c2][i]);
                if (!all_before && !all_after) break;
            }
            res += all_before || all_after;
        }
    }
    std::cout << res << '\n';
}
