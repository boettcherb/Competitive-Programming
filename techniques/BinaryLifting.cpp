/*

Binary Lifting / Doubling
=========================

Binary lifting is a technique for applying the same "next" operation many times
efficiently. Suppose every node x has exactly one successor: x -> next[x]

The basic problem is:
    "Starting at node x, where will I be after k applications of next?"

A naive solution applies next repeatedly: repeat k times: x = next[x]
This takes O(k) time per query, which is too slow when k is large.

Examples:
- Functional graphs: each node points to exactly one next node.
- Repeated permutations: one full operation maps each position to another
    position.
- Trees: next[x] can be the parent of x, allowing kth-ancestor queries.
- LCA: binary lifting is commonly extended to answer Lowest Common Ancestor
    queries efficiently.

------------------------------------------------------------
Key Idea
------------------------------------------------------------

Instead of storing only the 1-step successor, precompute successors after powers
of two:
    jump[0][x] = successor of x after 1 = 2^0 steps
    jump[1][x] = successor of x after 2 = 2^1 steps
    jump[2][x] = successor of x after 4 = 2^2 steps
    jump[3][x] = successor of x after 8 = 2^3 steps
    ...

jump[j][x] = "the node reached from x after exactly 2^j successor steps"

The recurrence is:
    jump[j][x] = jump[j - 1][jump[j - 1][x]]

To move 2^j steps from x:
    1. move 2^(j-1) steps
    2. then move another 2^(j-1) steps
So each table entry can be built from the previous row.

------------------------------------------------------------
Using the Binary Representation of k
------------------------------------------------------------

Every nonnegative integer k can be written as a sum of powers of two.

Example:
    k = 13 =  8  +  4  +  1
           = 2^3 + 2^2 + 2^0

So to move 13 steps, we can jump 1 step, then 4 steps, then 8 steps using the
precomputed table. That reduces a kth-successor query from O(k) to O(log k).

------------------------------------------------------------
Complexity
------------------------------------------------------------

Let:
    N = number of nodes
    LOG = number of binary-lifting levels

Preprocessing:            O(N * LOG)
Each kth-successor query: O(LOG)
Memory:                   O(N * LOG)

If k <= 1e9:  use LOG = 31
If k <= 1e18: use long long for k and LOG = 62.

*/

#include <vector>

std::vector<std::vector<int>> jump;

int kthSuccessor(int x, long long k) {
    for (int bit = 0; k > 0; ++bit) {
        if (k & 1LL)
            x = jump[bit][x];
        k >>= 1;
    }
    return x;
}

int main() {
    int LOG = 62;
    int n = 10;
    std::vector<int> next = { 4, 3, 7, 0, 6, 2, 1, 9, 5, 8 };

    jump[0] = next;
    for (int j = 1; j < LOG; ++j) {
        for (int x = 0; x < n; ++x) {
            jump[j][x] = jump[j - 1][jump[j - 1][x]];
        }
    }

    // get the 10th successor of vertex 3:
    // kthSuccessor(3, 10);
}
