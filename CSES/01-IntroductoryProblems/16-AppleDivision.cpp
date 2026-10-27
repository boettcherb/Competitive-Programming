#include <iostream>
#include <vector>

int n;
long long total = 0, res = 1e18;
std::vector<int> weights;

void rec(int cur, long long curSum) {
    if (cur == n) {
        res = std::min(res, std::abs(curSum * 2 - total));
        return;
    }
    rec(cur + 1, curSum + weights[cur]);
    rec(cur + 1, curSum);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    weights = std::vector<int>(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
        total += weights[i];
    }
    rec(0, 0);
    std::cout << res << '\n';
}
