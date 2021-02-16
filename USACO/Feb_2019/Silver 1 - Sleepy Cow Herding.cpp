#include <iostream>
#include <algorithm>

const int N = 1e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n, arr[N];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + n);
    int p1 = 0, p2 = 1, best = 1;
    bool inc_p2 = arr[1] - arr[0] < n;
    while (p2 < n) {
        if (inc_p2) {
            ++p2;
            if (arr[p2] - arr[p1] >= n) {
                best = std::max(best, p2 - p1);
                inc_p2 = false;
            }
        }
        else {
            ++p1;
            inc_p2 = arr[p2] - arr[p1] < n;
        }
    }
    best = std::max(best, p2 - p1);
    if (best == n - 1) {
        int spaces = 0;
        for (int i = 1; i < n; ++i) {
            spaces += arr[i] - arr[i - 1] > 1;
        }
        if (spaces == 1 && (arr[1] - arr[0] > 2 || arr[n - 1] - arr[n - 2] > 2)) {
            std::cout << 2 << '\n';
        }
        else {
            std::cout << 1 << '\n';
        }
    }
    else {
        std::cout << (n - best) << '\n';
    }
    int spaces = arr[n - 1] - arr[0] - (n - 1);
    int max = spaces - (std::min(arr[n - 1] - arr[n - 2], arr[1] - arr[0]) - 1);
    std::cout << max << '\n';
    return 0;
}
