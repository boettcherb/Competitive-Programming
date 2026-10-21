#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, res = 0;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < m; ++j) {
            res += str[j] == '#';
        }
    }
    std::cout << res << '\n';
}
