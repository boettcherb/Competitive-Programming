#include <iostream>

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
    long long res = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            res += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    std::cout << res << '\n';
    return 0;
}
