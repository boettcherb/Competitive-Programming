#include <iostream>

const int N = 2e5 + 10;

class SegmentTree {
    int n;
    int tree[4 * N];

    void build(int cur, int l, int r) {
        if (l == r) {
            tree[cur] = 1;
        } else {
            int mid = (l + r) / 2;
            build(cur * 2, l, mid);
            build(cur * 2 + 1, mid + 1, r);
            tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
        }
    }

    void update(int cur, int l, int r, int target) {
        if (l == r) {
            tree[cur] = 0;
        } else {
            int mid = (l + r) / 2;
            if (target <= mid) {
                update(cur * 2, l, mid, target);
            } else {
                update(cur * 2 + 1, mid + 1, r, target);
            }
            tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
        }
    }

    int find_kth(int cur, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int mid = (l + r) / 2;
        if (tree[cur * 2] >= k) {
            return find_kth(cur * 2, l, mid, k);
        } else {
            return find_kth(cur * 2 + 1, mid + 1, r, k - tree[cur * 2]);
        }
    }

public:
    SegmentTree(int numElements) {
        n = numElements;
        build(1, 1, n);
    }

    void update(int pos) {
        update(1, 1, n, pos);
    }

    int query(int k) {
        return find_kth(1, 1, n, k);
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    SegmentTree segtree(n);
    int pos = 0, numLeft = n;
    for (int i = 0; i < n; ++i) {
        pos = (pos + k) % numLeft--;
        int index = segtree.query(pos + 1);
        segtree.update(index);
        std::cout << index << ' ';
    }
    std::cout << '\n';
    return 0;
}
