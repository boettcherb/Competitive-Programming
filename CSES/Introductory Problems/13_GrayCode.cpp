#include <iostream>

const int N = 17;
const int MAX_NUM = 1e5;

void printNums(const int nums[N], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << nums[i];
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, pow = 1;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        pow *= 2;
    }
    int nums[N] = { 0 }, curNum = 0;
    bool used[MAX_NUM] = { true };
    printNums(nums, n);
    for (int i = 0; i < pow - 1; ++i) {
        int change = 1;
        for (int j = n - 1; j >= 0; --j) {
            int curChange = nums[j] == 0 ? change : -change;
            if (!used[curNum + curChange]) {
                curNum += curChange;
                used[curNum] = true;
                nums[j] = !nums[j];
                break;
            }
            change *= 2;
        }
        printNums(nums, n);
    }
    return 0;
}