#include <iostream>

long long count(long long x) {
    return x - x / 3 - x / 5 + x / 15;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
#endif

    long long n;
    std::cin >> n;
    long long l = 0, r = 2 * n;
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (count(mid) >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << '\n';
}
