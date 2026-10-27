#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<bool> seen(n + 1);
    for (int i = 1; i < n; ++i) {
        int x;
        std::cin >> x;
        seen[x] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            std::cout << i << '\n';
            break;
        }
    }
}
