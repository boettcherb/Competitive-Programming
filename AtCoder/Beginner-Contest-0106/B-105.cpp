#include <iostream>

int count_divisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count += i != n / i ? 2 : 1;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i += 2) {
        res += count_divisors(i) == 8;
    }
    std::cout << res << '\n';
}
