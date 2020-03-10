#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int nums[3];
    std::cin >> nums[0] >> nums[1] >> nums[2];
    std::sort(nums, nums + 3);
    if (nums[0] == 5 && nums[1] == 5 && nums[2] == 7) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}
