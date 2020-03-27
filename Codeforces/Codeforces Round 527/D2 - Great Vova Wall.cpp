#include <iostream>
#include <vector>

const int N = (int) (2e5 + 10);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, arr[N], max = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        max = std::max(max, arr[i]);
    }
    std::vector<int> heights;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != max) {
            int j = i;
            while (j < n && arr[j] != max) {
                if (heights.empty() || arr[j] < heights.back()) {
                    heights.push_back(arr[j]);
                } else if (!heights.empty() && heights.back() == arr[j]) {
                    heights.pop_back();
                } else {
                    std::cout << "NO" << '\n';
                    return 0;
                }
                ++j;
            }
            if (!heights.empty()) {
                std::cout << "NO" << '\n';
                return 0;
            }
            i = j;
        }
    }
    std::cout << "YES" << '\n';
    return 0;
}
