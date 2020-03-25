#include <iostream>
#include <vector>

const int N = (int) (2e5 + 10);
typedef std::vector<std::vector<int>> Graph;

Graph g;
int dp[N], color[N], res[N];

void dfs(int cur, int parent = -1) {
    dp[cur] = color[cur];
    for (int adj : g[cur]) {
        if (adj != parent) {
            dfs(adj, cur);
            dp[cur] += std::max(0, dp[adj]);
        }
    }
}

void reroot(int cur, int parent = -1) {
    res[cur] = dp[cur];
    for (int adj : g[cur]) {
        if (adj != parent) {
            dp[cur] -= std::max(0, dp[adj]);
            dp[adj] += std::max(0, dp[cur]);
            reroot(adj, cur);
            dp[adj] -= std::max(0, dp[cur]);
            dp[cur] += std::max(0, dp[adj]);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    g = Graph(n);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        color[i] = a ? 1 : -1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    reroot(0);
    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}
