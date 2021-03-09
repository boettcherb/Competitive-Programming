#include <iostream>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, T, arr[N];
    std::cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int p1 = 0, p2 = 0, curSum = arr[0], res = 0;
    while (p2 < n) {
        if (p1 > p2 || curSum < T) {
            curSum += arr[++p2];
        } else if (curSum > T) {
            curSum -= arr[p1++];
        } else {
            ++res;
            curSum += arr[++p2];
            curSum -= arr[p1++];
        }
    }
    std::cout << res << '\n';
    return 0;
}
