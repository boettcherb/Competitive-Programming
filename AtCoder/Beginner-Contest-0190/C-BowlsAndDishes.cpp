#include <iostream>
#include <vector>

int n, m, k, res = 0;
std::vector<std::pair<int, int>> dishes, conditions;
std::vector<int> plates;

void rec(int pos) {
    if (pos == k) {
        int satisfied = 0;
        for (auto [a, b] : conditions) {
            if (plates[a] > 0 && plates[b] > 0)
                ++satisfied;
        }
        res = std::max(res, satisfied);
        return;
    }
    ++plates[dishes[pos].first];
    rec(pos + 1);
    --plates[dishes[pos].first];
    ++plates[dishes[pos].second];
    rec(pos + 1);
    --plates[dishes[pos].second];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    conditions = std::vector<std::pair<int, int>>(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> conditions[i].first >> conditions[i].second;
    }
    std::cin >> k;
    dishes = std::vector<std::pair<int, int>>(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> dishes[i].first >> dishes[i].second;
    }
    plates = std::vector<int>(n + 1);
    rec(0);
    std::cout << res << '\n';
}
