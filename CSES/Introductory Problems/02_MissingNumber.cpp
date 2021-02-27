#include <iostream>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    bool found[N] = { false };
    for (int i = 0; i < n - 1; ++i) {
        int a;
        std::cin >> a;
        found[a - 1] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (!found[i]) {
            std::cout << (i + 1) << '\n';
            break;
        }
    }
    return 0;
}
