#include <iostream>
#include <vector>
#include <string>

const int N = 1e5 + 10;

std::vector<std::vector<int>> adj(N);
std::string types;
bool visited[N] = { false };
int comp[N];

void dfs(int cur, char type, int component) {
    visited[cur] = true;
    comp[cur] = component;
    for (int adjCow : adj[cur]) {
        if (!visited[adjCow] && types[adjCow] == type) {
            dfs(adjCow, type, component);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int n, m;
    std::cin >> n >> m >> types;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    int componentIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, types[i], componentIndex++);
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        char type;
        std::cin >> u >> v >> type;
        --u; --v;
        std::cout << (comp[u] != comp[v] || types[u] == type ? 1 : 0);
    }
    std::cout << '\n';
    return 0;
}