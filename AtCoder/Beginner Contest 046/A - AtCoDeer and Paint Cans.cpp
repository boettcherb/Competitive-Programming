#include <iostream>
#include <vector>

bool contains(const std::vector<int>& vec, int T) {
    for (int num : vec) {
        if (num == T) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> nums;
    for (int i = 0; i < 3; ++i) {
        int a;
        std::cin >> a;
        if (!contains(nums, a)) {
            nums.push_back(a);
        }
    }
    std::cout << nums.size() << '\n';
    return 0;
}
