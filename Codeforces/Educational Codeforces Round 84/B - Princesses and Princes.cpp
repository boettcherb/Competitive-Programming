#include <iostream>
#include <vector>

const int N = (int) (1e5 + 10);

bool mark(const std::vector<int>& list, bool taken[N]) {
    for (int num : list) {
        if (!taken[num]) {
            taken[num] = true;
            return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tc;
    std::cin >> tc;
    while (tc--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> lists(n);
        for (int i = 0; i < n; ++i) {
            int k;
            std::cin >> k;
            for (int j = 0; j < k; ++j) {
                int a;
                std::cin >> a;
                lists[i].emplace_back(a);
            }
        }
        int noneTaken = -1;
        bool taken[N] = { false };
        for (int i = 0; i < n; ++i) {
            if (!mark(lists[i], taken) && noneTaken == -1) {
                noneTaken = i + 1;
            }
        }
        if (noneTaken == -1) {
            std::cout << "OPTIMAL" << '\n';
        } else {
            std::cout << "IMPROVE" << '\n';
            for (int i = 1; i <= n; ++i) {
                if (!taken[i]) {
                    std::cout << noneTaken << ' ' << i << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
