#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int u, c, f;
    Edge(int _u, int _c, int _f) : u{_u}, c{_c}, f{_f} {}
};

struct Path {
    int pos, cost, flow;
    Path(int p, int c, int f) : pos{p}, cost{c}, flow{f} {}
    bool operator<(const Path& other) const {
        return (double) flow / cost < (double) other.flow / other.cost;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<Edge>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c, f;
        std::cin >> u >> v >> c >> f;
        --u; --v;
        g[u].emplace_back(v, c, f);
        g[v].emplace_back(u, c, f);
    }
    std::priority_queue<Path> pq;
    for (const Edge& e : g[0]) {
        pq.emplace(e.u, e.c, e.f);
    }
    std::vector<std::vector<std::pair<int, int>>> best(n);
    while (!pq.empty()) {
        Path p = pq.top();
        pq.pop();
        bool good = true;
        for (const auto& [c, f] : best[p.pos]) {
            if (p.cost >= c && p.flow <= f) {
                good = false;
                break;
            }
        }
        if (!good) continue;
        best[p.pos].emplace_back(p.cost, p.flow);
        for (const Edge& e : g[p.pos]) {
            pq.emplace(e.u, p.cost + e.c, std::min(p.flow, e.f));
        }
    }
    int res = 0;
    for (const auto& [c, f] : best[n - 1]) {
        res = std::max(res, (int) (f * 1000000.0 / c));
    }
    std::cout << res << '\n';
}
