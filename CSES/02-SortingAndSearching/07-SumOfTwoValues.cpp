#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;
    std::vector<std::pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    std::sort(arr.begin(), arr.end());
    int p1 = 0, p2 = n - 1;
    while (p1 < p2) {
        int sum = arr[p1].first + arr[p2].first;
        if (sum == x) {
            std::cout << arr[p1].second << ' ' << arr[p2].second << '\n';
            return 0;
        }
        if (sum < x) {
            ++p1;
        } else {
            --p2;
        }
    }
    std::cout << "IMPOSSIBLE" << '\n';
}
