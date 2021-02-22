#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

struct Edge {
    int v, cost, flow;
    Edge(int v, int c, int f) : v{v}, cost{c}, flow{f} {}
};

struct Path {
    int lastVertex, minFlow, totalCost;
    Path(int l, int f, int c) : lastVertex{l}, minFlow{f}, totalCost{c} {}
    bool operator<(const Path& other) const {
        return totalCost > other.totalCost;
    }
};

const int N = 1010;
const int INF = 2e9;
std::vector<std::vector<Edge>> adj(N);
bool visited[N];

void dijkstra(int dest, Path& res) {
    memset(visited, 0, N * sizeof(bool));
    std::priority_queue<Path> pq;
    pq.emplace(0, INF, 0);
    while (!pq.empty()) {
        Path cur = pq.top();
        pq.pop();
        if (cur.lastVertex == dest) {
            res = cur;
            return;
        }
        if (visited[cur.lastVertex]) {
            continue;
        }
        visited[cur.lastVertex] = true;
        for (const Edge& e : adj[cur.lastVertex]) {
            if (!visited[e.v]) {
                int minFlow = std::min(e.flow, cur.minFlow);
                pq.emplace(e.v, minFlow, e.cost + cur.totalCost);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, cost, flow;
        std::cin >> u >> v >> cost >> flow;
        --u; --v;
        adj[u].emplace_back(v, cost, flow);
        adj[v].emplace_back(u, cost, flow);
    }
    int res = 0;
    while (true) {
        Path path(0, 0, 0);
        dijkstra(n - 1, path);
        if (path.lastVertex == 0) {
            break;
        }
        res = std::max(res, path.minFlow * 1000000 / path.totalCost);
        for (int i = 0; i < n; ++i) {
            for (int j = adj[i].size() - 1; j >= 0; --j) {
                if (adj[i][j].flow <= path.minFlow) {
                    adj[i].erase(adj[i].begin() + j);
                }
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}
