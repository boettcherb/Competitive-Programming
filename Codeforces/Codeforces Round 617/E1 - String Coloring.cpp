#include <iostream>
#include <string>
#include <cstring>

const int N = 210;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::string str;
    std::cin >> n >> str;
    int colors[N];
    memset(colors, -1, 4 * n);
    bool failed = false;
    for (int i = 0; i < n && !failed; ++i) {
        if (colors[i] == -1) {
            colors[i] = 0;
        }
        for (int j = i + 1; j < n; ++j) {
            if (str[j] < str[i]) {
                if (colors[j] == colors[i]) {
                    failed = true;
                    break;
                }
                colors[j] = !colors[i];
            }
        }
    }
    if (failed) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            std::cout << colors[i];
        }
        std::cout << '\n';
    }
    return 0;
}
