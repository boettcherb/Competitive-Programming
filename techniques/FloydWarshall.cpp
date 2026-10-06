/*

Floyd-Warshall
==============

Floyd-Warshall computes the shortest-path distance between EVERY pair of
vertices in a weighted graph (All-Pairs Shortest Path).

It is especially useful when:
    - The graph is small (typically N <= a few hundred).
    - You need many shortest-path queries between arbitrary pairs.
    - Edge weights may be negative, as long as there is no negative cycle.

Complexity:
    Time:  O(N^3)
    Space: O(N^2)

------------------------------------------------------------
Core Idea
------------------------------------------------------------

Let dist[i][j] = shortest known distance from i to j

Initially:
    dist[i][i] = 0
    dist[u][v] = edge weight for each edge u -> v
    all other distances = INF
    For multiple edges i -> j, store the minimum edge weight.

Then consider each vertex k as an allowed intermediate vertex:
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

After finishing iteration k, dist[i][j] is the shortest path from i to j
whose intermediate vertices may only come from {0, 1, ..., k}. This invariant
is why one pass of N outer iterations is enough. Repeated relaxation until
convergence is unnecessary.

------------------------------------------------------------
Negative Cycles
------------------------------------------------------------

Floyd-Warshall supports negative edge weights.
After the algorithm, dist[i][i] < 0 indicates a negative cycle involving i.

*/

#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = (1LL << 60);

void floydWarshall(std::vector<std::vector<long long>>& dist) {
    int n = (int) dist.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == INF) continue;
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
