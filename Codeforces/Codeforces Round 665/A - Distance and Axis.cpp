#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        int n, k;
        std::cin >> n >> k;
        std::cout << (n < k ? k - n : (n % 2 != k % 2)) << '\n';
    }
    return 0;
}
