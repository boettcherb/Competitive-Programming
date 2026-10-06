#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct TypeIndex {
    std::vector<int> base;
    std::map<int, std::vector<int>> mp;

    TypeIndex(std::vector<int>& pos, std::vector<int>& arr, int n) {
        base = std::vector<int>(n + 1);
        for (int i = 1; i <= n; ++i) {
            base[pos[i]] = arr[i];
        }
        for (int i = 1; i <= n; ++i) {
            mp[base[i]].push_back(i);
        }
    }

    bool query(int l, int r, int x) {
        if (mp.find(x) == mp.end()) return false;
        auto itr = std::lower_bound(mp[x].begin(), mp[x].end(), l);
        return itr != mp[x].end() && *itr <= r;
    }
};

std::vector<std::vector<int>> g;
std::vector<int> type, depth, parent, heavy, head, pos;
int curPos = 1;

int dfs(int cur, int par) {
    parent[cur] = par;
    int subtreeSize = 1, maxChildSize = 0;
    for (int child : g[cur]) {
        if (child == par) continue;
        depth[child] = depth[cur] + 1;
        int childSize = dfs(child, cur);
        subtreeSize += childSize;
        if (childSize > maxChildSize) {
            maxChildSize = childSize;
            heavy[cur] = child;
        }
    }
    return subtreeSize;
}

void hld(int cur, int top) {
    head[cur] = top;
    pos[cur] = curPos++;
    if (heavy[cur] == -1) return;
    hld(heavy[cur], top);
    for (int child : g[cur]) {
        if (child == parent[cur] || child == heavy[cur]) continue;
        hld(child, child);
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
    type = depth = parent = head = pos = std::vector<int>(n + 1);
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
    heavy = std::vector<int>(n + 1, -1);
    dfs(1, -1);
    hld(1, 1);
    TypeIndex index(pos, type, n);
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        std::cin >> u >> v >> t;
        bool found = false;
        while (head[u] != head[v] && !found) {
            if (depth[head[u]] > depth[head[v]]) std::swap(u, v);
            found = index.query(pos[head[v]], pos[v], t);
            v = parent[head[v]];
        }
        if (!found) {
            if (depth[u] > depth[v]) std::swap(u, v);
            found = index.query(pos[u], pos[v], t);
        }
        std::cout << found;
    }
    std::cout << '\n';
}
