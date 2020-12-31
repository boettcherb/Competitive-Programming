#include <iostream>

const int N = 100;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, l, arr[N];
    std::cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int res = 0;
    for (int length = l; length <= N; ++length) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += arr[i] / length;
        }
        res = std::max(res, count * length);
    }
    std::cout << res << '\n';
    return 0;
}