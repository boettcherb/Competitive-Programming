#include <iostream>
#include <cmath>

const int N = 132000;

struct SegmentTree {
    int numElements;
    bool startXOR;
    int tree[4 * N];

    SegmentTree(int* arr, int n, int logN) : numElements{ n }, startXOR{ !(logN & 1) } {
        build(arr, 1, 0, numElements - 1, startXOR);
    }

    void update(int index, int val) {
        update(1, 0, numElements - 1, index, val, startXOR);
    }

    int query() {
        return tree[1];
    }

private:
    void build(const int* arr, int cur, int left, int right, bool XOR) {
        if (left == right) {
            tree[cur] = arr[left];
        } else {
            int mid = (left + right) / 2;
            build(arr, cur * 2, left, mid, !XOR);
            build(arr, cur * 2 + 1, mid + 1, right, !XOR);
            tree[cur] = XOR ? tree[cur * 2] ^ tree[cur * 2 + 1] : tree[cur * 2] | tree[cur * 2 + 1];
        }
    }

    void update(int cur, int left, int right, int goalIndex, int val, bool XOR) {
        if (left == right) {
            tree[cur] = val;
        } else {
            int mid = (left + right) / 2;
            if (goalIndex <= mid) {
                update(cur * 2, left, mid, goalIndex, val, !XOR);
            } else {
                update(cur * 2 + 1, mid + 1, right, goalIndex, val, !XOR);
            }
            tree[cur] = XOR ? tree[cur * 2] ^ tree[cur * 2 + 1] : tree[cur * 2] | tree[cur * 2 + 1];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int logN, m, arr[N];
    std::cin >> logN >> m;
    int n = static_cast<int>(std::pow(2, logN));
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    SegmentTree segTree(arr, n, logN);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        segTree.update(--a, b);
        std::cout << segTree.query() << '\n';
    }
    return 0;
}
