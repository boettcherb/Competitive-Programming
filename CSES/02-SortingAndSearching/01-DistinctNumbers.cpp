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
    int res = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i - 1]) ++res;
    }
    std::cout << res << '\n';
}
