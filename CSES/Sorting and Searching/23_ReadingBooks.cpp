#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, max = 0;
    long long sum = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        max = std::max(max, a);
        sum += a;
    }
    std::cout << (max > sum / 2 ? max * 2 : sum) << '\n';
    return 0;
}
