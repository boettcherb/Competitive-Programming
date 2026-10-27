#include <iostream>
#include <vector>
#include <algorithm>

long long n, t;
std::vector<int> arr;

void rec(int cur, int e, long long curSum, std::vector<long long>& sums) {
    if (curSum > t) return;
    if (cur == e) {
        sums.push_back(curSum);
        return;
    }
    rec(cur + 1, e, curSum, sums);
    rec(cur + 1, e, curSum + arr[cur], sums);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> t;
    arr = std::vector<int>(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::vector<long long> s1, s2;
    rec(0, n / 2, 0, s1);
    rec(n / 2, n, 0, s2);
    std::sort(s2.begin(), s2.end());
    long long res = 0;
    for (long long s : s1) {
        auto itr = std::upper_bound(s2.begin(), s2.end(), t - s);
        if (itr != s2.begin()) {
            --itr;
            res = std::max(res, s + *itr);
        }
    }
    std::cout << res << '\n';
}
