#include <iostream>

const int N = 101;

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
        bool good = true, odd = arr[0] % 2;
        for (int i = 1; i < n; ++i) {
            if ((arr[i] % 2 == 0 && odd) || (arr[i] % 2 && !odd)) {
                good = false;
                break;
            }
        }
        std::cout << (good ? "YES" : "NO") << '\n';
    }
    return 0;
}
