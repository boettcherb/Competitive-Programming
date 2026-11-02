#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += std::abs(arr[i] - arr[n / 2]);
    }
    std::cout << res << '\n';
}
