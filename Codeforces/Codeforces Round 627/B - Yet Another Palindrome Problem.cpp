#include <iostream>

const int N = 5010;

bool hasPalindrome(const int arr[N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

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
        std::cout << (hasPalindrome(arr, n) ? "YES" : "NO") << '\n';
    }
    return 0;
}
