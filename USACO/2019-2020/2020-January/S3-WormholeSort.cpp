#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u{_u}, v{_v}, w{_w} {}
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int n, m;
std::vector<int> arr, parent, size;
std::vector<Edge> edges;

int find(int v) {
    return v == parent[v] ? v : parent[v] = find(parent[v]);
}

void merge(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (size[u] < size[v]) std::swap(u, v);
    parent[v] = u;
    size[u] += size[v];
}

bool canSort(int minWeight) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = m - 1; i >= 0; --i) {
        if (edges[i].w < minWeight) break;
        merge(edges[i].u, edges[i].v);
    }
    for (int i = 0; i < n; ++i) {
        if (find(i) != find(arr[i])) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
#endif

    std::cin >> n >> m;
    arr = parent = size = std::vector<int>(n);
    bool wormholesNeeded = false;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        --arr[i];
        if (arr[i] != i) wormholesNeeded = true;
    }
    if (!wormholesNeeded) {
        std::cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges.emplace_back(u - 1, v - 1, w);
    }
    std::sort(edges.begin(), edges.end());
    int l = edges[0].w, r = edges[m - 1].w;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (canSort(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << l << '\n';
}
