#include <iostream>
#include <vector>
#include <cmath>

const int N = 1010;

struct Node {
    int index, dist, parent = -1;
    std::vector<int> adj;
    Node(int i, int d) : index{ i }, dist{ d } {}
};

typedef std::vector<Node> Graph;
Graph g;
bool visited[N] = { false };

Node dfs(int cur, int parent = -1, int dist = 0) {
    visited[cur] = true;
    g[cur].dist = dist;
    g[cur].parent = parent;
    Node farthest = g[cur];
    for (int adj : g[cur].adj) {
        if (adj != parent) {
            Node curFarthest = dfs(adj, cur, dist + 1);
            if (curFarthest.dist > farthest.dist) {
                farthest = curFarthest;
            }
        }
    }
    return farthest;
}

std::pair<int, int> findCenter(int cur) {
    Node V = dfs(dfs(cur).index);
    int center = V.index;
    for (int i = 0; i < V.dist / 2; ++i) {
        center = g[center].parent;
    }
    return {V.dist, center};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    g.reserve(n + 1);
    for (int i = 0; i < n; ++i) {
        g.emplace_back(Node(i, 0));
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        g[u].adj.push_back(v);
        g[v].adj.push_back(u);
    }
    std::vector<std::pair<int, int>> trees; // diameter, center index
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            trees.emplace_back(findCenter(i));
        }
    }
    int maxDiameter = -1;
    int center = -1;
    for (std::pair<int, int>& tree : trees) {
        if (tree.first > maxDiameter) {
            maxDiameter = tree.first;
            center = tree.second;
        }
    }
    std::vector<std::pair<int, int>> addedEdges;
    addedEdges.reserve(n - m);
    for (std::pair<int, int>& tree : trees) {
        if (tree.second != center) {
            int diameter = 1 + (int) ceil(tree.first / 2.0) + (int) ceil(maxDiameter / 2.0);
            maxDiameter = std::max(maxDiameter, diameter);
            addedEdges.emplace_back(tree.second + 1, center + 1);
        }
    }
    std::cout << maxDiameter << '\n';
    for (const std::pair<int, int> edge : addedEdges) {
        std::cout << edge.first << ' ' << edge.second << '\n';
    }
    return 0;
}
