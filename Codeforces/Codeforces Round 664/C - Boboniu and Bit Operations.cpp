#include <iostream>

const int N = 600;
unsigned a[N], b[N];

bool minRes(unsigned num, int n, int m) {
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < m; ++j) {
            if (((a[i] & b[j]) | num) <= num) {
                found = true;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    unsigned res = 0;
    while (res < 512) {
        if (minRes(res, n, m)) {
            break;
        }
        ++res;
    }
    std::cout << res << '\n';
    return 0;
}
