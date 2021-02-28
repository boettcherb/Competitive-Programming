#include <iostream>
#include <algorithm>

const int N = 21;
long long n, totalSum = 0, arr[N];

long long rec(int pos, long long curSum) {
    if (pos == n - 1) {
        long long res1 = std::abs(curSum - (totalSum - curSum));
        curSum += arr[pos];
        long long res2 = std::abs(curSum - (totalSum - curSum));
        return std::min(res1, res2);
    }
    return std::min(rec(pos + 1, curSum), rec(pos + 1, curSum + arr[pos]));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        totalSum += arr[i];
    }
    std::cout << rec(0, 0) << '\n';
    return 0;
}