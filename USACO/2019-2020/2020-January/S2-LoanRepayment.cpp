#include <iostream>

long long n, k, m;

bool canRepay(long long x) {
    long long g = 0, days = 0;
    while (g < n) {
        long long y = (n - g) / x;
        if (y <= m) {
            days += (n - g) / m + ((n - g) % m != 0);
            break;
        }
        long long daysAtY = ((n - g) % x) / y + 1;
        days += daysAtY;
        g += daysAtY * y;
    }
    return days <= k;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
#endif

    std::cin >> n >> k >> m;
    long long l = 1, r = 1e12;
    while (l < r) {
        long long mid = l + (r - l + 1) / 2;
        if (canRepay(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << l << '\n';
}
