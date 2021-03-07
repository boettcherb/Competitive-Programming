#include <iostream>
#include <set>

const int N = 2e5 + 10;

struct Range {
    int index, l, r;
    Range(int i, int l, int r) : index{i}, l{l}, r{r} {}
};

struct compareStart {
    bool operator()(const Range& r1, const Range& r2) {
        return r1.l == r2.l ? r1.r > r2.r : r1.l < r2.l;
    }
};

struct compareEnd {
    bool operator()(const Range& r1, const Range& r2) {
        return r1.r == r2.r ? r1.l > r2.l : r1.r < r2.r;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, a, b;
    std::cin >> n;
    std::set<Range, compareStart> start;
    std::set<Range, compareEnd> end, end2;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        start.emplace(i, a, b);
        end.emplace(i, a, b);
        end2.emplace(i, a, b);
    }
    bool contains[N] = { false }, containedBy[N] = { false };
    for (const Range& r : start) {
        auto itr = end.lower_bound(r);
        contains[r.index] = itr != end.begin();
        end.erase(r);
        itr = end2.lower_bound(r);
        auto itr2 = end2.begin();
        while (itr2 != itr) {
            containedBy[(*itr2).index] = true;
            itr2 = end2.erase(itr2);
        }
        end2.erase(r);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << contains[i] << ' ';
    } std::cout << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << containedBy[i] << ' ';
    } std::cout << '\n';
    return 0;
}
