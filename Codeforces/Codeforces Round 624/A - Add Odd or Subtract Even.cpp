#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int tc;
    std::cin >> tc;
    while (tc--) {
        int a, b;
        std::cin >> a >> b;
        bool odd = std::abs(a - b) % 2;
        if (a == b) {
            std::cout << 0 << '\n';
        } else if (a > b) {
            std::cout << (odd ? 2 : 1) << '\n';
        } else {
            std::cout << (odd ? 1 : 2) << '\n';
        }
    }
    return 0;
}
