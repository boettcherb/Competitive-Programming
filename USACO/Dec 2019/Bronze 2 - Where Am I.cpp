#include <iostream>
#include <string>
#include <set>

const int N = 105;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n;
    std::string str;
    std::cin >> n >> str;
    for (int k = 1; k <= n; ++k) {
        std::set<std::string> strs;
        for (int i = 0; i <= n - k; ++i) {
            std::string cur = str.substr(i, k);
            strs.emplace(cur);
        }
        if (strs.size() == n - k + 1) {
            std::cout << k << '\n';
            break;
        }
    }
    return 0;
}