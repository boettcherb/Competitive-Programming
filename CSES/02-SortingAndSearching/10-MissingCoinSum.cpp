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
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > sum + 1) break;
        sum += arr[i];
    }
    std::cout << (sum + 1) << '\n';
}
