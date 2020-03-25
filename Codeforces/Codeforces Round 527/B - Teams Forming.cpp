#include <iostream>
#include <algorithm>

const int N = 101;

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
    int res = 0;
    for (int i = 0; i < n; i += 2) {
        res += arr[i + 1] - arr[i];
    }
    std::cout << res << '\n';
    return 0;
}
