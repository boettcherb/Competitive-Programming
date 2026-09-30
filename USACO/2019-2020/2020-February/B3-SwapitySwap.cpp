#include <iostream>
#include <vector>
#include <algorithm>

void applyReversals(std::vector<int>& cows, int a1, int a2, int b1, int b2) {
    std::reverse(cows.begin() + a1, cows.begin() + a2 + 1);
    std::reverse(cows.begin() + b1, cows.begin() + b2 + 1);
}

bool isOrig(const std::vector<int>& cows) {
    for (int i = 1; i < (int) cows.size(); ++i) {
        if (cows[i] != i) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
#endif

    int n, k, a1, a2, b1, b2;
    std::cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    std::vector<int> cows(n + 1);
    for (int i = 1; i <= n; ++i) {
        cows[i] = i;
    }
    int count = 0;
    do {
        applyReversals(cows, a1, a2, b1, b2);
        ++count;
    } while (count < k && !isOrig(cows));
    if (count < k) {
        k %= count;
        for (int i = 0; i < k; ++i) {
            applyReversals(cows, a1, a2, b1, b2);
        }
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << cows[i] << '\n';
    }
}
