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
    long long res = arr[0] != 1, curSum = arr[0];
    for (int i = 1; i < n && !res; ++i) {
        if (curSum < arr[i] - 1) {
            res = curSum + 1;
        }
        curSum += arr[i];
    }
    std::cout << (res ? res : curSum + 1) << '\n';
}
