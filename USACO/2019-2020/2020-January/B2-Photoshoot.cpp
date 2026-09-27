#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
#endif

    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n - 1), seen(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> b[i];
    }
    for (int i = 1; i < b[0]; ++i) {
        std::fill(seen.begin(), seen.end(), 0);
        a[0] = i;
        seen[i] = true;
        bool good = true;
        for (int j = 0; j < n - 1; ++j) {
            int num = b[j] - a[j];
            if (num <= 0 || num > n || seen[num]) {
                good = false;
                break;
            }
            seen[num] = true;
            a[j + 1] = num;
        }
        if (good) break;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}
