#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;

class SegmentTree {
    int n;
    int tree[4 * N] = { 0 };

    void update(int cur, int l, int r, int target, int val) {
        if (l == r) {
            tree[cur] = val;
        } else {
            int mid = (l + r) / 2;
            if (target <= mid)
                update(cur * 2, l, mid, target, val);
            else
                update(cur * 2 + 1, mid + 1, r, target, val);
            tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
        }
    }

    int query(int cur, int cl, int cr, int tl, int tr) {
        if (cr < tl || cl > tr)
            return 0;
        if (cl >= tl && cr <= tr)
            return tree[cur];
        int mid = (cl + cr) / 2;
        int resLeft = query(cur * 2, cl, mid, tl, tr);
        int resRight = query(cur * 2 + 1, mid + 1, cr, tl, tr);
        return resLeft + resRight;
    }

public:
    SegmentTree(int numElements) : n{numElements} {}

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

};

struct Range {
    int l, r, index;
    bool operator<(const Range& other) const {
        return l == other.l ? r > other.r : l < other.l;
    }
} ranges[N];

struct Point {
    int p, index;
    bool left;
    Point() = default;
    Point(int p, int i, bool l) : p{p}, index{i}, left{l} {}
    bool operator<(const Point& other) const {
        if (p == other.p) {
            if (!left && !other.left)
                return ranges[index].l > ranges[other.index].l;
            return !left;
        }
        return p < other.p;
    }
} points[2 * N];

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
    for (int i = 0; i < n; ++i) {
        points[i] = { ranges[i].l, i, true };
        points[i + n] = { ranges[i].r, i, false };
    }
    std::sort(points, points + 2 * n);
    int contains[N], containedBy[N];
    SegmentTree segtree(n);
    for (int i = 0; i < 2 * n; ++i) {
        if (points[i].left) {
            segtree.update(points[i].index, 1);
        } else {
            segtree.update(points[i].index, 0);
            int query = segtree.query(0, points[i].index);
            containedBy[ranges[points[i].index].index] = query;
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (!points[i].left) {
            int query = segtree.query(points[i].index, n - 1);
            contains[ranges[points[i].index].index] = query;
            segtree.update(points[i].index, 1);
        }
    }
    for (int i = 0; i < n; ++i)
        std::cout << contains[i] << ' ';
    std::cout << '\n';
    for (int i = 0; i < n; ++i)
        std::cout << containedBy[i] << ' ';
    std::cout << '\n';
    return 0;
}
