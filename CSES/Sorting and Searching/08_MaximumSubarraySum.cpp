#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    long long curSum = 0, res = -2e9;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        res = std::max(res, curSum + a);
        curSum = std::max(curSum + a, 0LL);
    }
    std::cout << res << '\n';
    return 0;
}
