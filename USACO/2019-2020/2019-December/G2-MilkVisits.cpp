#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Path {
    int top_node;
    std::vector<int> arr;
    std::map<int, std::vector<int>> idxs;

    void build() {
        for (int i = 0; i < (int) arr.size(); ++i) {
            idxs[arr[i]].push_back(i);
        }
    }

    bool contains(int l, int r, int x) {
        if (idxs.find(x) == idxs.end()) return false;
        auto itr = std::lower_bound(idxs[x].begin(), idxs[x].end(), l);
        return itr != idxs[x].end() && *itr <= r;
    }
};

std::vector<std::vector<int>> g;
std::vector<int> type, depth, parent, subtreeSize, path;
std::vector<Path> paths;

void dfs(int cur, int p, int d) {
    depth[cur] = d;
    subtreeSize[cur] = 1;
    parent[cur] = p;
    for (int child : g[cur]) {
        if (child == p) continue;
        dfs(child, cur, d + 1);
        subtreeSize[cur] += subtreeSize[child];
    }
}

void hld(int cur, int p, bool new_tree) {
    if (new_tree) {
        paths.push_back(Path());
        paths.back().top_node = cur;
    }
    path[cur] = (int) paths.size() - 1;
    paths.back().arr.push_back(type[cur]);
    int max_child = -1;
    for (int child : g[cur]) {
        if (child == p) continue;
        if (max_child == -1 || subtreeSize[child] > subtreeSize[max_child]) {
            max_child = child;
        }
    }
    if (max_child == -1) return;
    hld(max_child, cur, false);
    for (int child : g[cur]) {
        if (child == p || child == max_child) continue;
        hld(child, cur, true);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;
    type = depth = parent = subtreeSize = path = std::vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> type[i];
    }
    g = std::vector<std::vector<int>>(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0);
    hld(1, -1, true);
    for (Path& p : paths) {
        p.build();
    }
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        std::cin >> u >> v >> t;
        bool found = false;
        while (u != v && !found) {
            Path& uPath = paths[path[u]];
            Path& vPath = paths[path[v]];
            if (path[u] == path[v]) {
                if (depth[u] > depth[v]) std::swap(u, v);
                int td = depth[uPath.top_node];
                found = uPath.contains(depth[u] - td, depth[v] - td, t);
                break;
            }
            if (depth[uPath.top_node] > depth[vPath.top_node]) {
                std::swap(u, v);
            }
            Path& curPath = paths[path[v]];
            found = curPath.contains(0, depth[v] - depth[curPath.top_node], t);
            v = parent[curPath.top_node];
        }
        std::cout << (found || (u == v && type[u] == t));
    }
    std::cout << '\n';
}
