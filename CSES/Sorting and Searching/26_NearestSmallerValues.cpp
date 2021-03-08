#include <iostream>
#include <queue>

const int N = 2e5 + 10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, arr[N], res[N] = { 0 };
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::priority_queue<std::pair<int, int>> pq;
    for (int i = n - 1; i >= 0; --i) {
        while (!pq.empty() && pq.top().first > arr[i]) {
            res[pq.top().second] = i + 1;
            pq.pop();
        }
        pq.emplace(arr[i], i);
    }
    for (int i = 0; i < n; ++i)
        std::cout << res[i] << ' ';
    std::cout << '\n';
    return 0;
}
