#include <iostream>
#include <string>

const int N = 101;
const int INF = (int) (2e9);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, nums[N];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    int res = INF;
    for (int y = -100; y <= 100; ++y) {
        int cost = 0;
        for (int i = 0; i < n; ++i) {
            cost += (nums[i] - y) * (nums[i] - y);
        }
        res = cost < res ? cost : res;
    }
    std::cout << res << '\n';
    return 0;
}
