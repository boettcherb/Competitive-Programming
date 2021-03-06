#include <iostream>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, res = 0;
    std::cin >> n;
    bool seen[N] = { false };
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        res += seen[a + 1];
        seen[a] = true;
    }
    std::cout << (res + 1) << '\n';
}
