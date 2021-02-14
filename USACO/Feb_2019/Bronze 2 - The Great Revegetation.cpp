#include <iostream>
#include <vector>

const int N = 105;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    int seedType[N];
    for (int i = 0; i < n; ++i) {
        seedType[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        int available[4] = { 1, 1, 1, 1 };
        for (int adjVertex : adj[i]) {
            if (seedType[adjVertex] != -1) {
                available[seedType[adjVertex]] = 0;
            }
        }
        do {
            ++seedType[i];
        } while (!available[seedType[i]]);
        std::cout << (seedType[i] + 1);
    }
    std::cout << '\n';
    return 0;
}