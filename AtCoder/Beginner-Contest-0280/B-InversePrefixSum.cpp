#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << arr[0];
    for (int i = 1; i < n; ++i) {
        std::cout << ' ' << (arr[i] - arr[i - 1]);
    }
    std::cout << '\n';
}
