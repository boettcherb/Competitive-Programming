#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<double> arr(n);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        arr[i] = (arr[i] + 1) / 2.0;
        if (i < k) sum += arr[i];
    }
    double res = sum;
    for (int i = k; i < n; ++i) {
        sum += arr[i] - arr[i - k];
        res = std::max(res, sum);
    }
    std::cout << std::fixed << std::setprecision(12) << res << '\n';
}
