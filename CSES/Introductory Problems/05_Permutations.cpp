#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    if (n == 2 || n == 3) {
        std::cout << "NO SOLUTION" << '\n';
    } else {
        for (int i = 2; i <= n; i += 2) {
            std::cout << i << ' ';
        }
        for (int i = 1; i <= n; i += 2) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
