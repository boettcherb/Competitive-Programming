#include <iostream>
#include <vector>

const int N = (int) (2e5 + 10);
typedef std::vector<std::vector<int>> Graph;

long long sum[N], vals[N];
long long curRes = 0, ans = 0;
Graph g;

void dfs(int cur, int parent = -1, long long depth = 0) {
    curRes += depth * vals[cur];
    sum[cur] = vals[cur];
    for (int adj : g[cur]) {
        if (adj != parent) {
            dfs(adj, cur, depth + 1);
            sum[cur] += sum[adj];
        }
    }
}

void reroot(int cur, int parent = -1) {
    ans = std::max(ans, curRes);
    for (int adj : g[cur]) {
        if (adj != parent) {
            curRes -= sum[adj];
            sum[cur] -= sum[adj];
            sum[adj] += sum[cur];
            curRes += sum[cur];
            reroot(adj, cur);
            curRes -= sum[cur];
            sum[adj] -= sum[cur];
            sum[cur] += sum[adj];
            curRes += sum[adj];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> vals[i];
    }
    g = Graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    reroot(0);
    std::cout << ans << '\n';
    return 0;
}
