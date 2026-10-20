#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    std::vector<int> in(n), top, dp(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[--u].push_back(--v);
        ++in[v];
    }
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        top.push_back(cur);
        for (int adj : g[cur]) {
            --in[adj];
            if (in[adj] == 0) q.push(adj);
        }
    }
    int res = 0;
    for (int v : top) {
        for (int adj : g[v]) {
            dp[adj] = std::max(dp[adj], dp[v] + 1);
        }
        res = std::max(res, dp[v]);
    }
    std::cout << res << '\n';
}
