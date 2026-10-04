#include <iostream>
#include <vector>

std::vector<int> clk, clk_orig;
std::vector<std::vector<int>> g;

void add(int& num, int x) {
    num += x;
    while (num > 12) num -= 12;
}

bool dfs(int cur, int parent) {
    for (int adj : g[cur]) {
        if (adj == parent) continue;
        add(clk[adj], 1);
        dfs(adj, cur);
        int toAdd = 12 - clk[adj];
        add(clk[adj], toAdd);
        add(clk[cur], toAdd + 1);
    }
    return clk[cur] == 12 || clk[cur] == 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
#endif

    int n;
    std::cin >> n;
    clk_orig = std::vector<int>(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> clk_orig[i];
    }
    g = std::vector<std::vector<int>>(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        clk = clk_orig;
        res += dfs(i, -1);
    }
    std::cout << res << '\n';
}
