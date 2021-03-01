#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, k, desired[N], actual[N];
    std::cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> desired[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> actual[i];
    }
    std::sort(desired, desired + n);
    std::sort(actual, actual + m);
    int d = 0, a = 0, res = 0;
    while (d < n && a < m) {
        if (actual[a] < desired[d] - k) {
            ++a;
        } else if (actual[a] > desired[d] + k) {
            ++d;
        } else {
            ++res;
            ++a;
            ++d;
        }
    }
    std::cout << res << '\n';
    return 0;
}
