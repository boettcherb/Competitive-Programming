/*

Disjoint Set Union (DSU) / Union-Find
=====================================

Disjoint Set Union (DSU), also called Union-Find, is a data structure for
maintaining a collection of disjoint sets under two main operations:

1. find(x): Return a representative (root) of the set containing x.
2. merge(a, b): Merge the sets containing a and b.

The most common use is to answer connectivity questions efficiently:
    "Are a and b currently in the same connected component?"
This can be checked with: find(a) == find(b)

Example:
Suppose we have:  0 -- 1     2 -- 3
Initially there are two connected components: {0, 1} {2, 3}

If we add an edge: 1 -- 2
Then DSU can merge the two components: {0, 1, 2, 3}

Basic Representation:
- Each node stores a parent: parent[x]
- A root is a node whose parent is itself: parent[x] == x
- All nodes in one set ultimately lead to the same root.

------------------------------------------------------------
Find
------------------------------------------------------------

find(x): The find operation follows parent pointers until reaching the root.

Naive version:
    int find(int x) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }

However, repeatedly following long chains can become slow. DSU therefore uses
an optimization called Path Compression, which makes every visited node point
directly to the root. With path compression, DSU trees become very shallow and
queries essentially become O(1).

Recursive implementation:
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

------------------------------------------------------------
Merge
------------------------------------------------------------

merge(a, b): combine the components containing a and b

Naive Implementation:
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        parent[a] = b;
        return true;
    }

When merging two components, we could arbitrarily make one root point to the
other: parent[rootB] = rootA; But this can create tall trees. Instead, keep
track of each component's size: size[root] and always attach the smaller tree
underneath the larger tree. This is called "Union by Size" and it helps
performance by keeping DSU trees shallow.

Optimal implementation:
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        parent[b] = a;
        if (size[a] < size[b]) {
            std::swap(a, b);
        }
        size[a] += size[b];
        return true;
    }

------------------------------------------------------------
Complexity
------------------------------------------------------------

Using both optimizations (path compression and union by size) makes DSU
operations extremely fast. For N elements and many operations, the amortized
complexity is O(alpha(N)) per operation, where alpha is the inverse Ackermann
function. alpha(N) grows so slowly that for every practical input size,
alpha(N) <= about 4 or 5. So DSU operations are effectively constant time. The
typical total complexity for M operations is O(M * alpha(N)), which is usually
treated as nearly O(M).

------------------------------------------------------------
Typical Pattern
------------------------------------------------------------

Initialize: parent[i] = i, size[i] = 1
Find: find(x)
Merge: merge(a, b)
Connectivity: find(a) == find(b)
Component size: size[find(x)]

Important rule:
Only roots have meaningful component sizes. If x is not a root, then size[x]
may be stale or irrelevant. To get the size of the component containing x, use
size[find(x)].

*/

#include <vector>

std::vector<int> parent, size;

int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

bool merge(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return false;
    if (size[a] < size[b]) std::swap(a, b);
    parent[b] = a;
    size[a] += size[b];
    return true;
}

int main() {
    int n = 10;
    parent = size = std::vector<int>(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}
