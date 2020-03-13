#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int tc;
    std::cin >> tc;
    while (tc--) {
        int n, m;
        std::cin >> n >> m;
        std::cout << (n % m == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}
