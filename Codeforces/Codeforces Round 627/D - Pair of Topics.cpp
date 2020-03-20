#include <iostream>
#include <algorithm>

const int N = (int) (2e5 + 10);

int binarySearch(const int arr[N], int T, int n) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] >= T) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, a[N], b[N], diffs[N];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        diffs[i] = a[i] - b[i];
    }
    std::sort(diffs, diffs + n);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int diff = a[i] - b[i];
        res += n - binarySearch(diffs, -diff + 1, n);
        if (diff > 0) {
            --res;
        }
    }
    std::cout << res / 2 << '\n';
    return 0;
}
