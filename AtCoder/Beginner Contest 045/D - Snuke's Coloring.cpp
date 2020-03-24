#include <iostream>
#include <set>

struct SubRect {
    int X, Y;
    int count;
    SubRect(int x, int y) : X{ x }, Y{ y }, count{ 1 } {}
    bool operator<(const SubRect& other) const {
        return X == other.X ? Y < other.Y : X < other.X;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long h, w, n;
    std::cin >> h >> w >> n;
    std::set<SubRect> set;
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        for (int x = a - 2; x <= a; ++x) {
            for (int y = b - 2; y <= b; ++y) {
                if (x > 0 && y > 0 && x < h - 1 && y < w - 1) {
                    SubRect cur(x, y);
                    auto itr = set.find(cur);
                    if (itr != set.end()) {
                        cur.count += itr->count;
                        set.erase(*itr);
                    }
                    set.emplace(cur);
                }
            }
        }
    }
    long long res[10] = { 0 }, sum = 0;
    for (SubRect rect : set) {
        ++res[rect.count];
        ++sum;
    }
    res[0] = (h - 2) * (w - 2) - sum;
    for (long long count : res) {
        std::cout << count << '\n';
    }
    return 0;
}
