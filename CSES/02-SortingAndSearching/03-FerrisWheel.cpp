#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;
    std::vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }
    std::sort(weights.begin(), weights.end());
    int p1 = 0, p2 = n - 1, res = 0;
    while (p1 <= p2) {
        if (weights[p1] + weights[p2] <= x) {
            ++p1;
        }
        --p2;
        ++res;
    }
    std::cout << res << '\n';
}
