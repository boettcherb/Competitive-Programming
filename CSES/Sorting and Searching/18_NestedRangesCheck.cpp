#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;

struct Range {
    int index, l, r;
    bool operator<(const Range& other) const {
        return l == other.l ? r > other.r : l < other.l;
    }
} ranges[N];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> ranges[i].l >> ranges[i].r;
        ranges[i].index = i;
    }
    std::sort(ranges, ranges + n);
    int contains[N] = { 0 }, containedBy[N] = { 0 };
    int max = 0, min = 2e9;
    for (int i = 0; i < n; ++i) {
        if (max >= ranges[i].r) {
            containedBy[ranges[i].index] = 1;
        }
        max = std::max(max, ranges[i].r);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (min <= ranges[i].r) {
            contains[ranges[i].index] = 1;
        }
        min = std::min(min, ranges[i].r);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << contains[i] << ' ';
    } std::cout << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << containedBy[i] << ' ';
    } std::cout << '\n';
    return 0;
}
