#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        int n, even = 0, odd = 0;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            if (num % 2) {
                ++odd;
            } else {
                ++even;
            }
        }
        std::cout << (odd == 0 || (even == 0 && n % 2 == 0) ? "NO" : "YES") << '\n';
    }
    return 0;
}
