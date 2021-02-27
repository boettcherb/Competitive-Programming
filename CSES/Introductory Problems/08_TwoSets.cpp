#include <iostream>
#include <set>

const int N = 1e6 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n;
    std::cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << "YES" << '\n';
        long long remaining = sum / 2;
        bool used[N] = { false };
        int numUsed = 0;
        for (int i = n; i > 0; --i) {
            ++numUsed;
            if (remaining <= i) {
                used[remaining] = true;
                break;
            }
            used[i] = true;
            remaining -= i;
        }
        std::cout << numUsed << '\n';
        for (int i = 1; i <= n; ++i) {
            if (used[i]) {
                std::cout << i << ' ';
            }
        }
        std::cout << '\n' << (n - numUsed) << '\n';
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                std::cout << i << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}
