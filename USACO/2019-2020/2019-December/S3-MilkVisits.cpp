#include <iostream>
#include <vector>
#include <string>

int n, m;
std::string type;
std::vector<std::vector<int>> tree;
std::vector<int> group;

void dfs(int cur, int parent, int groupIndex) {
    group[cur] = groupIndex;
    for (const int adj : tree[cur]) {
        if (adj == parent || type[adj] != type[cur]) continue;
        dfs(adj, cur, groupIndex);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
#endif

    std::cin >> n >> m >> type;
    tree = std::vector<std::vector<int>>(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    group = std::vector<int>(n, -1);
    int groupIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (group[i] != -1) continue;
        group[i] = ++groupIndex;
        dfs(i, -1, groupIndex);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        char milkType;
        std::cin >> u >> v >> milkType;
        --u; --v;
        std::cout << (group[u] != group[v] || type[u] == milkType);
    }
    std::cout << '\n';
}
