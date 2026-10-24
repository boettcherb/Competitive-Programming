#include <iostream>
#include <vector>

class DSU {
    std::vector<int> parent, size;

public:
    explicit DSU(int n) {
        parent = size = std::vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int v) {
        return v == parent[v] ? v : parent[v] = find(parent[v]);
    }

    bool merge(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return false;
        if (size[u] < size[v]) std::swap(u, v);
        size[u] += size[v];
        parent[v] = u;
        return true;
    }
};

struct Edge {
    int v, cost;
    Edge(int _v, int c) : v{_v}, cost{c} {}
};

std::vector<std::vector<Edge>> g;
std::vector<long long> cost;
std::vector<bool> seen, hasInfCycle;

bool dfs(int cur) {
    seen[cur] = true;
    for (const Edge& e : g[cur]) {
        if (seen[e.v]) {
            if (e.cost != cost[e.v] - cost[cur]) return true;
            continue;
        }
        cost[e.v] = cost[cur] + e.cost;
        if (dfs(e.v)) return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;
    g = std::vector<std::vector<Edge>>(n);
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        --u; --v;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, -c);
        dsu.merge(u, v);
    }
    cost = std::vector<long long>(n, -1);
    seen = hasInfCycle = std::vector<bool>(n);
    for (int i = 0; i < n; ++i) {
        int root = dsu.find(i);
        if (seen[root]) continue;
        cost[root] = 0;
        hasInfCycle[root] = dfs(root);
    }
    for (int i = 0; i < q; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x; --y;
        if (dsu.find(x) != dsu.find(y)) {
            std::cout << "nan" << '\n';
        } else if (hasInfCycle[dsu.find(x)]) {
            std::cout << "inf" << '\n';
        } else {
            std::cout << (cost[y] - cost[x]) << '\n';
        }
    }
}
