#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<int> arr(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int p1 = 0, p2 = 0;
    long long sum = arr[0], res = 0;
    while (p2 < n) {
        if (sum >= k) {
            res += n - p2;
            sum -= arr[p1++];
            if (p1 > p2) sum += arr[++p2];
        } else {
            sum += arr[++p2];
        }
    }
    std::cout << res << '\n';
}
