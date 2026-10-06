/*

Fenwick Tree / Binary Indexed Tree (BIT)
========================================

A Fenwick Tree maintains prefix sums over an array but allows point updates.
It uses the binary representation of a number to know which ranges the number
affects. Each number affects O(logN) ranges, so both updates and queries are
O(logN).

Fenwick Trees are similar to Segment Trees, but have some differences:
    Pros of Fenwick Tree:
        - easier to implement
        - more memory efficient (N space vs 4*N space)
        - slightly faster (same Big-O but smaller constant factors)
    Cons of Fenwick Tree:
        - Can only do point updates (segment trees can handle range updates
            efficiently with lazy propagation)
        - If the query for range [l, r] cannot be solved using prefix(r) -
            prefix(l-1), such as the min, max or gcd of a range, a Fenwick
            tree cannot be used. Good for: sums, XOR, multiplication, etc.

Supports:
    prefixSum(i)       -> sum of a[1..i]
    rangeSum(l, r)     -> sum of a[l..r]
    add(i, delta)      -> a[i] += delta
    setValue(i, value) -> a[i] = value

Complexity:
    Build:        O(N) with the linear constructor below
    Prefix query: O(log N)
    Range query:  O(log N)
    Update:       O(log N)
    Space:        O(N)

This implementation is 1-indexed.

*/

#include <cassert>
#include <vector>

class FenwickTree {
private:
    int n;
    std::vector<int> tree;

public:
    explicit FenwickTree(int _n) : n(_n), tree(_n + 1, 0) {}

    FenwickTree(const std::vector<int>& arr, int _n) : FenwickTree(_n) {
        assert(_n > 0);
        assert((int) arr.size() == n + 1);
        for (int i = 1; i <= n; ++i) {
            tree[i] += arr[i];
            int parent = i + (i & -i);
            if (parent <= n) {
                tree[parent] += tree[i];
            }
        }
    }

    // Add delta to tree[index]
    void add(int index, int delta) {
        assert(1 <= index && index <= n);
        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    // Set tree[index] to value
    void setValue(int index, int value) {
        assert(1 <= index && index <= n);
        int current = rangeSum(index, index);
        add(index, value - current);
    }

    // Return sum of tree[1..index]
    int prefixSum(int index) const {
        assert(0 <= index && index <= n);
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }

    // Return sum of tree[l..r]
    int rangeSum(int l, int r) const {
        assert(1 <= l && l <= r && r <= n);
        return prefixSum(r) - prefixSum(l - 1);
    }
};
