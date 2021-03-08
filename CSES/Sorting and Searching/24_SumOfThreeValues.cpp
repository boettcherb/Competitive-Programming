#include <iostream>
#include <algorithm>

const int N = 5010;
int n, T;
std::pair<int, int> nums[N];

int foundThird(int i, int j) {
    int t = T - nums[i].first - nums[j].first;
    int l = j + 1, r = n - 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (nums[mid].first == t)
            return mid;
        if (nums[mid].first < t)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return nums[l].first == t ? l : nums[r].first == t ? r : -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i].first;
        nums[i].second = i;
    }
    std::sort(nums, nums + n);
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int k = foundThird(i, j);
            if (k != -1) {
                std::cout << (nums[i].second + 1) << ' ';
                std::cout << (nums[j].second + 1) << ' ';
                std::cout << (nums[k].second + 1) << '\n';
                return 0;
            }
        }
    }
    std::cout << "IMPOSSIBLE" << '\n';
    return 0;
}
