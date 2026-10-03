#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int MOD = 1e9 + 7;

struct Line {
    std::vector<long long> pos, prefix;

    void fill_prefix() {
        std::sort(pos.begin(), pos.end());
        prefix.push_back(pos[0]);
        for (int i = 1; i < (int) pos.size(); ++i) {
            prefix.push_back(prefix[i - 1] + pos[i]);
        }
    }

    long long totalDistFrom(long long x) const {
        int idx = (int) (std::lower_bound(pos.begin(), pos.end(), x) - pos.begin());
        int n = (int) pos.size();
        long long right = prefix[n - 1] - prefix[idx] - (n - idx - 1) * x;
        long long left = x * idx - (idx == 0 ? 0 : prefix[idx - 1]);
        return right + left;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifndef DB_LOCAL
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
#endif

    int n;
    std::cin >> n;
    std::map<long long, Line> h_lines, v_lines;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        v_lines[x].pos.push_back(y);
        h_lines[y].pos.push_back(x);
    }
    for (auto& [x, line] : v_lines) line.fill_prefix();
    for (auto& [y, line] : h_lines) line.fill_prefix();
    long long res = 0;
    for (const auto& [x, line] : v_lines) {
        for (int i = 0; i < (int) line.pos.size(); ++i) {
            long long y = line.pos[i];
            res += line.totalDistFrom(y) * h_lines[y].totalDistFrom(x);
            res %= MOD;
        }
    }
    std::cout << res << '\n';
}
