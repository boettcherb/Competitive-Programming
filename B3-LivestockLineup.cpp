#include <iostream>
#include <vector>
#include <algorithm>

using Constraint = std::pair<std::string, std::string>;

bool satisfied(const Constraint& c, const std::vector<std::string>& order) {
    for (int i = 0; i < (int) order.size() - 1; ++i) {
        if (order[i] == c.first && order[i + 1] == c.second) return true;
        if (order[i] == c.second && order[i + 1] == c.first) return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
#endif

    int n;
    std::cin >> n;
    std::vector<Constraint> constraints;
    for (int i = 0; i < n; ++i) {
        std::string c1, c2, s;
        std::cin >> c1 >> s >> s >> s >> s >> c2;
        constraints.emplace_back(c1, c2);
    }
    std::vector<std::string> order = {
        "Beatrice", "Belinda", "Bella", "Bessie",
        "Betsy", "Blue", "Buttercup", "Sue"
    };
    do {
        bool all_satisfied = true;
        for (const Constraint& constraint : constraints) {
            if (!satisfied(constraint, order)) {
                all_satisfied = false;
                break;
            }
        }
        if (all_satisfied) break;
    } while (std::next_permutation(order.begin(), order.end()));
    for (int i = 0; i < (int) order.size(); ++i) {
        std::cout << order[i] << '\n';
    }
}
