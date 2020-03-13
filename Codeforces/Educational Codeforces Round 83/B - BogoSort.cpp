#include <iostream>
#include <algorithm>

const int N = 110;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int tc;
    std::cin >> tc;
    while (tc--) {
        int n, arr[N];
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        std::sort(arr, arr + n);
        for (int i = n - 1; i >= 0; --i) {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
