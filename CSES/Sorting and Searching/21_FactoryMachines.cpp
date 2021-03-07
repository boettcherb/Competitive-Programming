#include <iostream>

const int N = 2e5 + 10;
int n, t, arr[N];

bool check(long long time) {
    long long amount = 0;
    for (int i = 0; i < n && amount < t; ++i) {
        amount += time / arr[i];
    }
    return amount >= t;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    long long l = 0, r = 1e18;
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << (check(l) ? l : r) << '\n';
    return 0;
}
