#include <iostream>

const int N = 10;

bool digits(int n, const bool *arr) {
    while (n > 0) {
        if (arr[n % 10]) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    bool arr[N] = { false };
    for (int i = 0; i < k; ++i) {
        int a;
        std::cin >> a;
        arr[a] = true;
    }
    int res = n;
    while (!digits(res, arr)) {
        ++res;
    }
    std::cout << res << '\n';
    return 0;
}
