#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int INF = 2e9 + 10;

class SegmentTree {
    int n;
    std::vector<int> tree;

    int combine(int a, int b) {
        return std::min(a, b);
    }

    void build(int cur, int tl, int tr, const std::vector<int>& arr) {
        if (tl == tr) {
            tree[cur] = arr[tl];
        } else {
            int mid = tl + (tr - tl) / 2;
            build(cur * 2, tl, mid, arr);
            build(cur * 2 + 1, mid + 1, tr, arr);
            tree[cur] = combine(tree[cur * 2], tree[cur * 2 + 1]);
        }
    }

    void update(int cur, int tl, int tr, int index, int val) {
        if (tl == tr) {
            tree[cur] = std::min(val, tree[cur]);
        } else {
            int mid = tl + (tr - tl) / 2;
            if (index <= mid) {
                update(cur * 2, tl, mid, index, val);
            } else {
                update(cur * 2 + 1, mid + 1, tr, index, val);
            }
            tree[cur] = combine(tree[cur * 2], tree[cur * 2 + 1]);
        }
    }

    int query(int cur, int tl, int tr, int ql, int qr) {
        if (ql <= tl && tr <= qr) {
            return tree[cur];
        }
        if (qr < tl || ql > tr) {
            return INF;
        }
        int mid = tl + (tr - tl) / 2;
        return combine(
            query(cur * 2, tl, mid, ql, qr),
            query(cur * 2 + 1, mid + 1, tr, ql, qr)
        );
    }

public:
    SegmentTree(int _n, const std::vector<int>& arr) : n{_n} {
        tree = std::vector<int>(4 * n);
        build(1, 0, n - 1, arr);
    }

    void update(int index, int val) {
        update(1, 0, n - 1, index, val);
    }

    int query(int l) {
        return query(1, 0, n - 1, l, n - 1);
    }
};

struct Event {
    int x, y, index;
    bool start;
    Event(int _x, int _y, int i, bool s) : x{_x}, y{_y}, index{i}, start{s} {}
    bool operator<(const Event& other) {
        return x == other.x ? y < other.y : x < other.x;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
#endif

    int n, p;
    std::cin >> n >> p;
    std::vector<Event> events;
    std::vector<int> yVals;
    for (int i = 0; i < p; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        events.emplace_back(x1, y1, i, true);
        events.emplace_back(x2, y2, i, false);
        yVals.push_back(y1);
        yVals.push_back(y2);
    }
    std::sort(events.begin(), events.end());
    std::sort(yVals.begin(), yVals.end());
    std::map<int, int> index;
    for (int i = 0; i < 2 * p; ++i) {
        if (i > 0 && yVals[i] == yVals[i - 1]) continue;
        index[yVals[i]] = i;
    }
    SegmentTree st(2 * p, std::vector<int>(2 * p, INF));
    std::vector<int> dp(2 * p);
    for (int i = 2 * p - 1; i >= 0; --i) {
        Event e = events[i];
        if (e.start) {
            st.update(index[e.y], dp[e.index] + e.x + e.y);
        } else {
            int min_cost = st.query(index[e.y]);
            if (min_cost == INF)
                dp[e.index] = (n - e.x) + (n - e.y);
            else
                dp[e.index] = min_cost - (e.x + e.y);
        }
    }
    int res = 2 * n;
    for (int i = 0; i < 2 * p; ++i) {
        if (!events[i].start) continue;
        res = std::min(res, dp[events[i].index] + events[i].x + events[i].y);
    }
    std::cout << res << '\n';
}
