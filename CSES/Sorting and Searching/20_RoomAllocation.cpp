#include <iostream>
#include <algorithm>
#include <queue>

const int N = 2e5 + 10;

struct Point {
    int p, index;
    bool left;
    bool operator<(const Point& other) const {
        return p == other.p ? left : p < other.p;
    }
} points[2 * N];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].p >> points[i + n].p;
        points[i].index = points[i + n].index = i;
        points[i].left = true;
        points[i + n].left = false;
        pq.push(i + 1);
    }
    std::sort(points, points + 2 * n);
    int room[N], max = 0, cur = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (points[i].left) {
            room[points[i].index] = pq.top();
            pq.pop();
        } else {
            pq.push(room[points[i].index]);
        }
        cur += points[i].left ? 1 : -1;
        max = std::max(max, cur);
    }
    std::cout << max << '\n';
    for (int i = 0; i < n; ++i)
        std::cout << room[i] << ' ';
    std::cout << '\n';
    return 0;
}
