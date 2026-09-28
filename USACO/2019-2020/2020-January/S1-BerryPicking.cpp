#include <iostream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
#endif
 
    int n, k;
    std::cin >> n >> k;
    std::priority_queue<int> pq_orig;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        pq_orig.push(x);
    }
    int res = 0;
    for (int maxBasket = 1; maxBasket <= 1000; ++maxBasket) {
        std::priority_queue<int> pq = pq_orig;
        int filled = 0;
        while (!pq.empty() && filled < k) {
            int val = pq.top();
            if (val < maxBasket) break;
            pq.pop();
            filled += val / maxBasket;
            if (val % maxBasket != 0) {
                pq.push(val % maxBasket);
            }
        }
        if (filled < k / 2) break;
        if (filled >= k) {
            res = std::max(res, k / 2 * maxBasket);
            continue;
        }
        int curRes = (filled - k / 2) * maxBasket;
        for (int i = 0; i < k - filled; ++i) {
            if (pq.empty()) break;
            curRes += pq.top();
            pq.pop();
        }
        res = std::max(res, curRes);
    }
    std::cout << res << '\n';
}
