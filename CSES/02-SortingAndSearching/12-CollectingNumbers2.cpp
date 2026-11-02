#include <iostream>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr(n + 1), index(n + 2);
    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i];
        index[arr[i]] = i;
    }
    index[n + 1] = n + 1;
    auto contribution = [&](int x) {
        return index[x] > index[x + 1];
    };
    int rounds = 1;
    for (int i = 1; i < n; ++i) {
        rounds += contribution(i);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::set<int> vals = { arr[a] - 1, arr[a], arr[b] - 1, arr[b] };
        for (int v : vals) rounds -= contribution(v);
        std::swap(index[arr[a]], index[arr[b]]);
        std::swap(arr[a], arr[b]);
        for (int v : vals) rounds += contribution(v);
        std::cout << rounds << '\n';
    }
}
