#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, arr[N];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + n);
    int mid = arr[n / 2];
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += std::abs(arr[i] - mid);
    }
    std::cout << res << '\n';
}
